#ifndef BROKER_H
#define BROKER_H
/**
  @file Broker.h

  @date 06 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include <Arduino.h>
#include "Network.h"

/**
  @class Broker
  @brief Gestisce colloquio con broker utilizzando risorse di rete fornite da un oggetto network
  azioni gestite: chiamata delle api get e set e relativi valori di ritorno
*/
class Broker{
  protected:
    Network* _net; /**< @var oggetto di connessione alla rete */

    /**
     * emissione di messaggi su seriale per debug della deserializzazione da JSON
     * @return void
     */
    void deserializaDbg();
  public:

    /**
     * constructor
     * @param net oggetto di connessione alla rete
     */
    Broker(Network* net);

    /**
     * chiamata alla api get
     * @param key chiave da ricercare
     * @return String il valore associato alla chiave, NULL se chiave non trovata
     */
    String get(String key);

    /**
     * chiamata alla api set
     * @param key chiave da impostare
     * @param value valore associato alla chiave
     * @return String conferma il valore in caaso di successo, NULL se in errore
     */
    String set(String key, String value);

};
#endif