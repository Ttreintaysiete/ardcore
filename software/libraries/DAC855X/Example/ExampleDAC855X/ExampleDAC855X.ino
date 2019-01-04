//This program exemplifies the use 
//of the library on a Texas Instruments 
//DAC8552 2-channel chip. Channel A 
//will make a saw tooth wave, and 
//channel B will make a sine wave, sumultaneously.

#include <DAC855X.h>

DAC855X dac;

const float radian = 0.000488281F;
uint32_t sen;
float numpi = 0.0;

void setup() {
  dac.setPins(11, 13, 10);
  dac.initializeDAC855X();
}

void loop() {
  int ChA = analogRead(0)/4;

  for (int i=1; i<4096; i=i+ChA){
    int dacA = i*16; // Channel A shows the sawtooth wave
    dac.setChipChanValue(1, 0, dacA); // DAC8552 chip, channel A
    int ChA = analogRead(0);
    delay(1);
    Serial.print("Channel A = ");
    Serial.print(ChA);
    numpi = PI*radian*i; //Channel B shows the sinewave
    int dacB = (1+(sin(numpi)))*32768;
    dac.setChipChanValue(1, 1, dacB); // DAC8552 chip, channel B
    delay(1);
    int ChB = analogRead(1);
    Serial.print("\t Channel B = ");
    Serial.println(ChB);
  }  
}




