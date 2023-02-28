/**
  @file TempSensor.cpp

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include "TempSensor.h"


const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

TempSensor::TempSensor(byte pin){
  // initialize _pin
  _pin=pin;
  _filter=TEMP_FILTER_1;
}

void TempSensor::setFilter(byte f){
  //accetta solo i valori previsti, li altri sono ignorati
  switch (f){
    case TEMP_FILTER_1:
    case TEMP_FILTER_2:
    case TEMP_FILTER_5:
    case TEMP_FILTER_10:
      _filter=f;
      break;
  }
}

byte TempSensor::getFilter(){
  return _filter;
}

/*
 * vedi https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
 */
float TempSensor::getRawTemperature(){
  int a = analogRead(_pin);
  float R = 1023.0/a-1.0;
  R = R0*R;
  return 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
}

float TempSensor::getTemperature(){
  return round((10.0/_filter)*getRawTemperature())*_filter/10.0;
}
