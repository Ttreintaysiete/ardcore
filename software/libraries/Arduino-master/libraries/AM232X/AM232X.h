#ifndef AM232X_H
#define AM232X_H
//
//    FILE: AM232X.h
//  AUTHOR: Rob Tillaart
// PURPOSE: AM232X library for Arduino .
// VERSION: 0.1.3
// HISTORY: See AM232X.cpp
//     URL: https://github.com/RobTillaart/Arduino/tree/master/libraries/
//
// Released to the public domain
//

#include "Wire.h"
#include "Arduino.h"

#define AM232X_LIB_VERSION          "0.1.3"

#define AM232X_OK                    0
#define AM232X_ERROR_UNKNOWN        -10
#define AM232X_ERROR_CONNECT        -11
#define AM232X_ERROR_FUNCTION       -12
#define AM232X_ERROR_ADDRESS        -13
#define AM232X_ERROR_REGISTER       -14
#define AM232X_ERROR_CRC_1          -15
#define AM232X_ERROR_CRC_2          -16
#define AM232X_ERROR_WRITE_DISABLED -17
#define AM232X_ERROR_WRITE_COUNT    -18
#define AM232X_MISSING_BYTES        -19
/*
from datasheet
0x80: not support function code
0x81: Read an illegal address
0x82: write data beyond the scope
0x83: CRC checksum error
0x84: Write disabled
*/

class AM232X
{
public:
  #ifdef ESP8266
  void begin(uint8_t sda, uint8_t scl);
  #endif
  void begin();

  int read();
  int getModel();
  int getVersion();
  uint32_t getDeviceID();

  int getStatus();
  int getUserRegisterA();
  int getUserRegisterB();

  int setStatus(uint8_t value);
  int setUserRegisterA(int value);
  int setUserRegisterB(int value);

  float humidity;
  float temperature;

private:
  uint8_t bits[8];

  int _readRegister(uint8_t reg, uint8_t cnt);
  int _writeRegister(uint8_t reg, uint8_t cnt, int16_t value);
  uint16_t crc16(uint8_t *ptr, uint8_t len);
};

#endif
// END OF FILE