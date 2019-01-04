//
//    FILE: AM2322.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo sketch for AM2322 I2C humidity & temperature sensor
//
// HISTORY:
// 0.1.0 - 2017-12-11 initial version
//
// Released to the public domain
//

#include <AM232X.h>

AM232X AM2322;

void setup()
{
  Wire.begin();

  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(AM232X_LIB_VERSION);
  Serial.println();

  Serial.println("Type,\tStatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  // READ DATA
  Serial.print("AM2322, \t");
  int status = AM2322.read();
  switch (status)
  {
  case AM232X_OK:
    Serial.print("OK,\t");
    break;
  default:
    Serial.print(status);
    Serial.print("\t");
    break;
  }
  // DISPLAY DATA, sensor only returns one decimal.
  Serial.print(AM2322.humidity, 1);
  Serial.print(",\t");
  Serial.println(AM2322.temperature, 1);

  delay(2000);
}

//
// END OF FILE
//