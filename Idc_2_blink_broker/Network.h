#ifndef NETWORK_H
#define NETWORK_H
/**
  @file Network.h

  @date 06 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include <Arduino.h>
#include <ESP8266WiFiMulti.h>

/**
  @class Network
  @brief Gestisce connessione con rete wifi
  Azioni disponibili: chiamata http get
*/
class Network{
  protected:
    ESP8266WiFiMulti WiFiMulti; /**< @var oggetto di connessione alla wifi */
  public:

    /**
     * constructor
     * @param ssid identificativo di wifi
     * @param password per l'accesso alla wifi
     */
    Network(String ssid, String password);

    /**
     * Chiamata http get
     * @param url indirizzo da chiamare
     * @return String il messaggio restituito dal server, vuoto se in errore
     */
    String httpGET(String url);//

};
#endif
