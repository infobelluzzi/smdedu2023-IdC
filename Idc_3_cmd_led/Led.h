#ifndef LED_H
#define LED_H
/**
  @file Led.h

  @date 23 03 2022
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include <Arduino.h>

/**
  @class Led
  @brief Manage an LED.
  Managed actions: Off/On
*/
class Led{
  protected:
    byte _pin; /**< @var pin number */
  public:

    /**
     * constructor
     * @param pin An Led needs a pin number
     */
    Led(byte pin);

    /**
     * Switch on the led using digitalWrite
     * @return void
     */
    void on();

    /**
     * Switch off the led
     * @return void
     */
    void off();//digital off

    /**
     * level getter
     * @return current level
     */
    byte getLevel() const ;

    /**
     * pin getter
     * @return pin number
     */
    byte getPin() const ;
    
    /**
     * abstract status getter
     * @return true if level >0
     */
    boolean isOn() const ;
    
    /**
     * abstract status getter
     * @return true if level==0
     */
    boolean isOff() const ;
};
#endif
