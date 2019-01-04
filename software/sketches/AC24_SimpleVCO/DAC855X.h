/*************************************************************************
**  Device: DAC855X                                                 	**
**  File:   DAC855X.h - Library for DACs of TI							**
*************************************************************************/
#ifndef DAC855X_h
#define DAC855X_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class DAC855X
{
  public:
    DAC855X();   
    void setPinsChip(uint8_t DIN, uint8_t SCK, uint8_t SYNC, uint8_t CHIPX);
	void setChanValue(uint8_t chan, uint16_t value);
	void initializeDAC855X();
	
  private:
    uint8_t _DIN;
    uint8_t _SCK;
    uint8_t _SYNC;
	uint8_t _CHIPX;
};
#endif