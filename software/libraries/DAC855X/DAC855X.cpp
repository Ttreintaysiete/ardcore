/*************************************************************************
** Library for Digital to Analogic Converters by Texas Instruments      **
** DAC8550, DAC8551, DAC8552, DAC8554, DAC8555 on Arduino.              **
** By Renato Ianhez                                                     **
*************************************************************************/
#include "DAC855X.h"

DAC855X::DAC855X() {
}
void DAC855X::setPins(int DIN, int SCK, int SYNC) {
	_DIN = DIN;
	_SCK = SCK;
	_SYNC = SYNC;
	pinMode(_DIN,OUTPUT);
	pinMode(_SCK,OUTPUT);
	pinMode(_SYNC,OUTPUT);
	
}

void DAC855X::initializeDAC855X() {
	Serial.begin(9600);
	// initialize pins:
	digitalWrite(_SYNC, HIGH);
	delay(1);
	SPI.begin();// initialize SPI
	delay(1);
	SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE1));
	delay(100);
}
void DAC855X::setChipChanValue(int CHIPX, int chan, int value) {
	int header;
	//Choose of chips and channels - define the header byte
	switch(CHIPX) {
		case 0: //DAC8550 and 8551
			header = 0x00;
			break;
		case 1: //DAC8552
			switch(chan) {
				case 0: //Channel A
					header = 0x10;
					break;
				case 1: //Channel B
					header = 0x24;
					break;
				default:
					Serial.println("Wrong channel for DAC8552. Choose 0, 1. Using default = 0");
					header = 0x10;
			}
			break;
		case 2: //DAC8554 and 8555
			switch(chan) {
				case 0: //Channel A
					header = 0x00;
					break;
				case 1: //Channel B
					header = 0x04;
					break;
				case 2: //Channel C
					header = 0x08;
					break;
				case 3: //Channel D
					header = 0x0C;
					break;
				default:
					Serial.println("Wrong channel for DAC8554. Choose 0, 1, 2 or 3. Using default = 0");
					header = 0x00;
			}
			break;
		default:
			Serial.println("Wrong DAC. Choose 0, 1 or 2");
	}
	digitalWrite(_SYNC, LOW); //Turn on the transfer
	byte hiByte = highByte(value); //Divides the integer into two bytes
	byte loByte = lowByte(value);
	SPI.transfer(header); //Transfer configuration byte
	SPI.transfer(hiByte); //Transfer data bytes 15 to 8
	SPI.transfer(loByte); //Transfer data bytes 7 to 0
	digitalWrite(_SYNC, HIGH); //Turn off the transfer
}


