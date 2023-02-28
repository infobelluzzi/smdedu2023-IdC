/**
  @file idc.ino

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

  progetto di supporto per il laboratorio "Internet delle Cose" - SchoolMakerDay 20/2/2023

  fase 0 - progetto vuoto

*/

// librerie ---------------------------------------
#include <Arduino.h>
// classi del progetto ----------------------------
#include "Led.h"
#include "TempSensor.h"
#include "Network.h"
#include "Broker.h"

// configurazione --------------------------------
// ssid e password per wifi 
#define STASSID "SSID"
#define STAPSK "PASSWORD"

//velocità per la seriale 
#define SERIAL_BAUD_RATE 115200

// pin dei dispositivi
#define LED_PIN 4
#define TEMP_SENSOR_PIN A0 

// chiavi da utilizzare nel broker
String BASE_KEY = "";

// fine configurazione ---------------------------

// oggetti di interazione con i dispositivi
Led led(LED_PIN); //si sccupa del led in comando e lettura di stato
TempSensor ts(A0); //si occupa del sensore di temperatura, fornisce il valore corrente
Network net(STASSID,STAPSK); //si occupa della connessione di rete con Wifi
Broker broker(&net); //si occupa del colloquio con il broker e delle relative api get e set

// variabili per immagine di comando e stato------
String cmdOn=""; // ON/OFF/AUTO command image
String cmdTemp=""; // Temperature command image
String staOn=""; // ON/OFF status image
String staTemp=""; // Tempemperature status image

// -----------------------------------------------

void setup() {
  //attiva il canale seriale
  initSerial();
}

void loop() {
  
  //aggiorna conmandi da broker

  //campiona stato
  
  //azioni coerenti ai comandi/stati
  
  //le azioni potrebbero aver modificato lo stato, aggiorna stato

  //se c'è una modifica di stato aggiorna in locale e su broker
  
  //attesa sospensiva
  //in un progetto realtime occorre una attesa senza sospensione
  delay(1000);
}

 /**
  * inizializzazione del canale seriale
  * @return void
  */
void initSerial(){
  Serial.begin(SERIAL_BAUD_RATE);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[main] [SERIAL SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
}
