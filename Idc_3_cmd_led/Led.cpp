/**
  @file Led.cpp

  @date 23 03 2022
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include "Led.h"
Led::Led(byte pin){
  // initialize the digital pin as an output.
  _pin=pin;
  pinMode(pin, OUTPUT);     
  //initialize level OFF
  off();
}

void Led::on(){
  digitalWrite(_pin, HIGH); 
}

void Led::off(){
  digitalWrite(_pin, LOW); 
}

byte Led::getLevel() const {
  return digitalRead(_pin);
}

byte Led::getPin() const {
  return _pin;
}

boolean Led::isOn() const {
  return digitalRead(_pin)==HIGH;
}

boolean Led::isOff() const {
  return digitalRead(_pin)==LOW;
}
