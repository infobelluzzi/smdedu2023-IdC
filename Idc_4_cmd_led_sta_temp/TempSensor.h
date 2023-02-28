#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H
/**
  @file TempSensor.h

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include <Arduino.h>

#define TEMP_FILTER_1 1
#define TEMP_FILTER_2 2
#define TEMP_FILTER_5 5
#define TEMP_FILTER_10 10

/**
  @class TempSensor
  @brief Gestisce il sensore di temperatura Grove.
  Azioni: lettura di temperatura corrente  raw o filtrata
*/
class TempSensor{
  protected:
    byte _pin; /**< @var numero di pin */
    byte _filter; /**< @var base del filtro */
  public:

    /**
     * constructor
     * @param pin Il sensore di temperatura richiede un pin analogico
     */
    TempSensor(byte pin);

    /**
     * Imposta il filtro
     * si raccomnada l'uso delle costanti TEMP_FILTER, altri valori saranno ignorati
     * @param f valori ammessi : 1,2,5,10 (decimi) di arrotondamento
     */
    void setFilter(byte f);

    /**
     * Restituisce il filtro
     * @return byte valori ammessi : 1,2,5,10 (decimi) di arrotondamento
     */
    byte getFilter();

    /**
     * Campiona la temperatura corrente
     * @return float temperatura corrente grezza
     */
    float getRawTemperature();//

    /**
     * Campiona e filtra la temperatura
     * @return float temperatura corrente arrotondata in base al valore di _filter
     */
    float getTemperature();//

};
#endif
