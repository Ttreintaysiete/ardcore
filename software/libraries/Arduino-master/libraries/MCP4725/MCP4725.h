#ifndef MCP4725_H
#define MCP4725_H
//
//    FILE: MCP4725.h
//  AUTHOR: Rob Tillaart
// PURPOSE: Simple MCP4725 DAC (12 bit I2C) library for Arduino
// VERSION: 0.1.7
// HISTORY: See MCP4725.cpp
//     URL:
//
// Released to the public domain
//

#include <Wire.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "Wstring.h"
#include "Wiring.h"
#endif

#define MCP4725_VERSION         "0.1.7"

// regisiterMode
#define MCP4725_DAC             0x40
#define MCP4725_DACEEPROM       0x60

// constants
#define MCP4725_MAXVALUE        4095

// errors
#define MCP4725_VALUE_ERROR     -999
#define MCP4725_REG_ERROR       -998

// page 22
#define MCP4725_GC_RESET        0x06
#define MCP4725_GC_WAKEUP       0x09

// powerDown Mode - TODO ENUM?
#define MCP4725_PDMODE_NORMAL   0x00
#define MCP4725_PDMODE_1K       0x01
#define MCP4725_PDMODE_100K     0x02
#define MCP4725_PDMODE_500K     0x03

// conditional to minimize footprint.
//#define MCP4725_EXTENDED
//#define MCP4725_POWERDOWNMODE

class MCP4725
{
public:
    explicit MCP4725(const uint8_t deviceAddress);

    void begin();
    // uses writeFastMode
    int setValue(const uint16_t value);
    // returns last value set - cached - much faster than readDAC();
    uint16_t getValue();

#ifdef MCP4725_EXTENDED
    int writeDAC(const uint16_t value, const bool EEPROM = false);
    bool RDY();
    uint16_t readDAC();
    uint16_t readEEPROM();
#endif

#ifdef MCP4725_POWERDOWNMODE
    // experimental
    int writePowerDownMode(const uint8_t PDM, const bool EEPROM = false);
    uint8_t readPowerDownModeEEPROM();
    uint8_t readPowerDownModeDAC();
    int powerOnReset();
    int powerOnWakeUp();
#endif

private:
    uint8_t _deviceAddress;
    uint16_t _lastValue;
    uint8_t _powerDownMode;      // DATASHEET P15?
    int writeFastMode(const uint16_t value);

#ifdef MCP4725_EXTENDED
    int writeRegisterMode(const uint16_t value, const uint8_t reg);
    uint8_t readRegister(uint8_t* buffer, const uint8_t length);
#endif

#ifdef MCP4725_POWERDOWNMODE
    int generalCall(const uint8_t gc);
#endif

};

#endif
// END OF FILE