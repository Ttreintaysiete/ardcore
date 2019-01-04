/*************************************************************************
** Library for Digital to Analogic Converters by Texas Instruments      **
** DAC8550, DAC8551, DAC8552, DAC8554, DAC8555 on Arduino.              **
** By Renato Ianhez                                                     **
*************************************************************************/
#ifndef DAC855X_H
#define DAC855X_H

	#include "Arduino.h"
	#include "SPI.h"

		class DAC855X
		{
			public:
				DAC855X();
				void setPins(int DIN, int SCK, int SYNC);
				void setChipChanValue(int CHIPX, int chan, int value);
				void initializeDAC855X();

			private:
				int _DIN;
				int _SCK;
				int _SYNC;
				
		};
#endif
