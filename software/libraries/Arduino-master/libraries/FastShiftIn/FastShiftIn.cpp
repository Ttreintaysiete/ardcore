//
//    FILE: FastShiftIn.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.3
// PURPOSE: shiftin
//    DATE: 2013-09-29
//     URL:
//
// Released to the public domain
//

#include "FastShiftIn.h"

FastShiftIn::FastShiftIn(const uint8_t datapin, const uint8_t clockpin, const uint8_t bitOrder)
{
    _bitorder = bitOrder;
    _value = FASTSHIFTIN_NOVALUE;

    pinMode(datapin, INPUT);
    pinMode(clockpin, INPUT);

    // uint8_t _datatimer  = digitalPinToTimer(datapin);
    // if (_datatimer != NOT_ON_TIMER) turnOffPWM(_datatimer); TODO
    uint8_t _dataport   = digitalPinToPort(datapin);
    _datain = portOutputRegister(_dataport);
    _databit = digitalPinToBitMask(datapin);

    // uint8_t _clocktimer = digitalPinToTimer(clockpin);
    // if (_clocktimer != NOT_ON_TIMER) turnOffPWM(_clocktimer);
    uint8_t _clockport  = digitalPinToPort(clockpin);
    _clockin = portOutputRegister(_clockport);
    _clockbit = digitalPinToBitMask(clockpin);
}


int FastShiftIn::read()
{
    _value = 0;

    for (uint8_t i = 0, m = 1, n = 128; i < 8; i++, m <<=1, n >>= 1)
    {
        uint8_t oldSREG = SREG;
        cli();
        *_clockin |= _clockbit;

        if ((*_datain & _databit) > 0)
        {
            if (_bitorder == LSBFIRST)
            _value |= m;
            else
            _value |= n;
        }
        *_clockin &= ~_clockbit;
        SREG = oldSREG;
    }
    return _value;
}
// -- END OF FILE --