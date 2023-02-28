/**
  @file Broker.cpp

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include "Broker.h"
#include "Network.h"

#include <ArduinoJson.h>

#define BROKER_DEBUG true

String BASE_URL = "http://www.schoolmakerday.it/broker/";
//String BASE_URL = "http://192.168.1.8/broker/"; 
String GET_URL = BASE_URL+"get.php?key=";
String SET_URL_1 = BASE_URL+"set.php?key=";
String SET_URL_2 = "&value=";

/*
per dimensioni vedi https://arduinojson.org/v6/assistant
*/
const int docCapacity = 192; // > di JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(3);
StaticJsonDocument<docCapacity> answerDoc;
DeserializationError error;


Broker::Broker(Network* net){
  _net=net;
  if (BROKER_DEBUG) {
    Serial.printf("[broker] docCapacity: %d\n", docCapacity);
  }
}

String Broker::get(String key){
  const char * val;
  String msg=_net->httpGET(GET_URL + key);
  if (msg){
    error=deserializeJson(answerDoc,msg);
    if (BROKER_DEBUG) {
      deserializaDbg();
    }
    val=answerDoc["data"]["value"];    
  }
  else {
    val=NULL;
  }
  return val;
}

String Broker::set(String key, String value){
  const char * val;
  String msg=_net->httpGET(SET_URL_1 + key + SET_URL_2 + value);
  if (msg){
    error=deserializeJson(answerDoc,msg);
    if (BROKER_DEBUG) {
      deserializaDbg();
    }
    val=answerDoc["data"]["value"];    
  }
  else {
    val=NULL;
  }
  return val;
}

void Broker::deserializaDbg(){
  if(error){
    Serial.print("[broker] deserializeJson() failed: ");
    Serial.println(error.c_str());
  }
  else {
    Serial.println("[broker] deserializeJson() success: ");
    String sta=answerDoc["status"];
    Serial.println("\tstatus: "+sta);
    String key=answerDoc["data"]["key"];
    Serial.println("\tkey: "+key);
    String val=answerDoc["data"]["value"];
    Serial.println("\tval: "+val);
    String ts=answerDoc["data"]["ts"];
    Serial.println("\tts: "+ts);
  }
}




