//
//    FILE: FastShiftOut.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.5
// PURPOSE: shiftout that implements the Print interface
//    DATE: 2013-08-22
//     URL:
//
// Released to the public domain
//

#ifndef FastShiftOut_h
#define FastShiftOut_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define FASTSHIFTOUT_LIB_VERSION (F("0.1.5"))

#include "Print.h"

class FastShiftOut : public Print
{
public:
    FastShiftOut(const uint8_t, const uint8_t, const uint8_t);
    size_t write(const uint8_t);
    int read(void);

private:
    uint8_t _bitorder;
    int _value;

    uint8_t _databit;
    volatile uint8_t *_dataout;

    uint8_t _clockbit;
    volatile uint8_t *_clockout;
};

#endif
// -- END OF FILE --