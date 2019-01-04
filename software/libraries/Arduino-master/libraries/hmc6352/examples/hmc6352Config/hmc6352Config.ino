//
//    FILE: hmc6352Config.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: test app HMC6352 library for Arduino
//
// HISTORY:
// 0.1.0  - 2011-04-12 initial version
// 0.1.1  - 2017-09-13 renamed to .ino;
//
// Released to the public domain
//

#include <Wire.h>
#include <hmc6352.h>

hmc6352 Compass(33);

void setup()
{
  Serial.begin(19200);
  Serial.println("HMC6352: Config");
  Serial.println(HMC_LIB_VERSION);

  dumpEEPROM();
}
int x;

void loop()
{
  // SHOWMENU
  Serial.println("\n\n\t\tHMC6352 MENU\n");
  Serial.println("F : Factory Reset");
  Serial.println("E : Dump EEPROM & 2 RAM addresses");

  Serial.println("R : Dump RAM");

  Serial.println("A : ask sampling");
  Serial.println("Q : read sample");
  Serial.println("Z : continuous read (loop) - X to stop");

  Serial.println("W : WakeUp");
  Serial.println("S : Sleep");

  Serial.println("O : Output Modus Menu");
  Serial.println("7 : STANDBY MODE");
  Serial.println("8 : QUERY MODE");
  Serial.println("9 : CONTINUOUS MODE");

  Serial.println("C : Callibration On (!!)");
  Serial.println("X : Callibration Off (!!)");

  Serial.println("I : set I2C address (!!)");
  Serial.println("@ : reset (!!)");

  Serial.println("Enter your choice ...");

  // WAIT FOR COMMAND
  while (Serial.available() == 0);
  char cmd = Serial.read();

  // EXECUTE COMMAND
  switch(cmd)
  {
  case 'F':
    factoryReset();
    break;
  case 'E':
    dumpEEPROM();
    break;
  case 'R':
    dumpRAM();
    break;
  case 'A':
    askHeading();
    break;
  case 'Q':
    readHeading();
    break;
  case 'W':
    x = Compass.wakeUp();
    Serial.println(x, DEC);
    break;
  case 'S':
    x = Compass.sleep();
    Serial.println(x, DEC);
    break;
  case 'O':
    OutPutModusMenu();
    break;
  case '7':
    // mode , freq , reset
    Compass.setOperationalModus(STANDBY, 1, true);  // 10 default val
    Serial.println("Reboot Arduino");
    break;
  case '8':
    Compass.setOperationalModus(QUERY, 1, true);  // 10 default val
    Serial.println("Reboot Arduino");
    break;
  case '9':
    Compass.setOperationalModus(CONT, 20, true);  // 10 default val
    Serial.println("Reboot Arduino");
    break;
  case 'U':
    Compass.callibrationOn();
    break;
  case 'X':
    Compass.callibrationOff();
    break;
  case 'I':
    setI2Caddress();
    break;
  case '@':
    Compass.updateOffsets();
    break;
  case 'Z':
    while (1)
    {
      readHeading();
      if (Serial.available()>0)
      {
        Serial.read();
        break;
      }
      delay(50);  // 20 Hz
    }
    break;
  default:
    break;
  }
}

void OutPutModusMenu()
{
  Serial.println(Compass.getOutputModus());
  Serial.println("output modus value :");
  Serial.println("0 Heading (default)");
  Serial.println("1 Raw Magnetometer X");
  Serial.println("2 Raw Magnetometer Y");
  Serial.println("3 Magnetometer X");
  Serial.println("4 Magnetometer Y");
  // WAIT FOR PARAM
  while (Serial.available() == 0);
  char cmd = Serial.read();
  cmd -= '0'; // make a digit out of it
  int x = Compass.setOutputModus(cmd);
  Serial.print("Returns: ");
  Serial.println(x);
}

void askHeading()
{
  int x = Compass.askHeading();
  Serial.print("Returns: ");
  Serial.println(x);
}

void readHeading()
{
  int x = Compass.readHeading();
  Serial.print("DEGREE: ");
  Serial.println(x);
}

void factoryReset()
{
  Compass.factoryReset();
  Serial.println("Reboot Arduino");
}

void dumpRAM()
{
  Serial.println("\nDUMP RAM: (decimal values)");
  Serial.println("Size 256 bytes (?) meaning mostly unknown");
  for (int i = 0; i< 256; i++)
  {
    if (i % 16 == 0)
    {
      Serial.println();
      Serial.print(i, HEX);
      Serial.print(" : ");
    }
    Serial.print(Compass.readRAM(i), HEX);
    Serial.print("\t ");
  }
  Serial.println();
}

void dumpEEPROM()
{
  Serial.println("\nDUMP EEPROM: (decimal values)");
  Serial.println("Read datasheet for meaning\n");

  Serial.print("      I2C ADDRESS: 0x00 : ");
  Serial.println(Compass.readEEPROM(0), DEC);
  Serial.print("MAGN X OFFSET MSB: 0x01 : ");
  Serial.println(Compass.readEEPROM(1), DEC);
  Serial.print("MAGN X OFFSET LSB: 0x02 : ");
  Serial.println(Compass.readEEPROM(2), DEC);
  Serial.print("MAGN Y OFFSET MSB: 0x03 : ");
  Serial.println(Compass.readEEPROM(3), DEC);
  Serial.print("MAGN Y OFFSET LSB: 0x04 : ");
  Serial.println(Compass.readEEPROM(4), DEC);
  Serial.print("       Time Delay: 0x05 : ");
  Serial.println(Compass.readEEPROM(5), DEC);
  Serial.print("  Measurement Sum: 0x06 : ");
  Serial.println(Compass.readEEPROM(6), DEC);
  Serial.print(" Software Version: 0x07 : ");
  Serial.println(Compass.readEEPROM(7), DEC);
  Serial.print(" Operational Mode: 0x08 : ");
  Serial.println(Compass.readEEPROM(8), DEC);

  Serial.println("REGISTERS RAM");
  Serial.print("Operational Mode Control Byte: 0x74 : ");
  Serial.println(Compass.getOperationalModus(), BIN);
  Serial.print("Output Data Mode: 0x4E : ");
  Serial.println(Compass.getOutputModus(), BIN);
}

void setI2Caddress()
{
  Serial.print("Current I2C address : ");
  Serial.println(Compass.getI2CAddress());
  Serial.println();
  Serial.println("Give new value: (decimal, 2 digits)");
  Serial.println("00 to escape");

  while (Serial.available() < 2);
  int v1 = Serial.read();
  v1 -= '0';
  v1 *= 10;
  int v2 = Serial.read();
  v2 -= '0';
  v1 += v2;
  if (v1 == 0) return;
  Serial.println(v1);
  int x = Compass.setI2CAddress(v1);
  Serial.println(x);
  Serial.print("Current I2C address : ");
  Serial.println(Compass.getI2CAddress());

}

// END OF FILE
