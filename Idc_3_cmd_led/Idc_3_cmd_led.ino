/**
  @file idc.ino

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

  progetto di supporto per il laboratorio "Internet delle Cose" - SchoolMakerDay 20/2/2023

  fase 3 - comando e monitoraggio led da remoto via broker

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
String BASE_KEY = "gr";
String CMD_ON_KEY = BASE_KEY+"c_on"; //chiave per il comando ON/OFF/AUTO
String STA_ON_KEY = BASE_KEY+"s_on";  //chiave per lo stato del led ON/OFF

// fine configurazione ---------------------------

// abilitazione ai messaggi su seriale per il debug
#define MAIN_DEBUG true

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
  led.off();
  staOn=aggiornaStaOn();
  broker.set(STA_ON_KEY, staOn);
}

void loop() {
  
  //aggiorna conmandi da broker
  aggiornaCmdOn();

  //campiona stato
  String newStaOn=aggiornaStaOn();

  //azioni coerenti ai comandi/stati
  azioneOnOff(newStaOn);

  //le azioni potrebbero aver modificato lo stato, aggiorna stato
  newStaOn=aggiornaStaOn();

  //se c'è una modifica di stato aggiorna in locale e su broker
  if (newStaOn!=staOn){
    staOn=newStaOn;
    broker.set(STA_ON_KEY, staOn);
  }
  //attesa sospensiva
  //in un progetto realtime occorre una attesa senza sospensione
  delay(1000);
}

 /**
  * richiede al broker il valore di cmdOn
  * effettua verifica di validità
  * @return void
  */
void aggiornaCmdOn(){
  String newCmdOn=broker.get(CMD_ON_KEY); 
  newCmdOn.toUpperCase();//converte in tutto maiuscolo
  if (
    newCmdOn=="ON" ||
    newCmdOn=="OFF" 
  ) {
    //comando valido
    cmdOn=newCmdOn;
    if (MAIN_DEBUG) {
      Serial.println("[main] CmdOn: '"+newCmdOn+"'");
    }
  } else {
    // comando sconosciuto, ignora
    if (MAIN_DEBUG) {
      Serial.println("[main] CmdOn sconosciuto: '"+newCmdOn+"'");
    }
  }
}

  /**
  * richiede all'oggetto led il suo stato
  * e ne restituisce stringa corrispondente
  * @return String
  */
String aggiornaStaOn(){
  if (led.isOn()){
    return "ON";
  }
  return "OFF";   
}

 /**
  * azione di controllo diretto on/off
  * @param newStaOn stato corrente
  * @return String
  */
void azioneOnOff(String newStaOn){
  //verifico se stato è coerente a comando
  if (newStaOn!=cmdOn){
    //devo agire
    if (cmdOn=="ON"){
      led.on();
    }
    else {
      led.off();
    }
  }
  // else nothing to do!
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
