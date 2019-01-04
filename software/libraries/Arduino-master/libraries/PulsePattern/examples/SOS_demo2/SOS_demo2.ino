//
//    FILE: SOS_demo2.pde
//  AUTHOR: Rob Tillaart
//    DATE: 2012-11-23
//
// PUPROSE: demo of the PulsePattern Library
//          uses timer1
//

#include "PulsePattern.h"

// a pattern consists of durations of LOW and HIGH periods
// so the first line of the SOSpattern is 
// 500 units LOW, 500 units HIGH etc
// for a dutycycle of 50% LOW and HIGH should have equal periods
// NOTE max period = 4095.
// min period = about 12 
uint16_t SOSpattern[] = {  
  500,500,500,500,500,1500,  // SOS in morse
  1500,500,1500,500,1500,1500, 
  500,500,500,500,500,1500 };

uint16_t XYZpattern[] = {  
  100,100,100,100,100,100,  // SOS in morse
  500,500,500,500,500,500, 
  1000,1000,1000,1000,1000,1000 };

uint8_t patternSize = 18;
uint8_t startLevel = LOW;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start PulsePattern");

  // as the prescaler = 1024 the periods of the pattern are a 
  // few percent less than a millisecond
  PPGenerator.init(13, SOSpattern, patternSize, startLevel, PRESCALE_1024);
  PPGenerator.start();
}

void loop()
{
  // dummy code
  Serial.println(millis());
  delay(1000);
}

