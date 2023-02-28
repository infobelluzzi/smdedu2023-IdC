/**
  @file Network.cpp

  @date 04 02 2023
  @author Giovanni Ragno

  @copyright https://creativecommons.org/licenses/by-sa/4.0/

*/

#include "Network.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define NETWORK_DEBUG false

Network::Network(String ssid, String password){
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid.c_str(), password.c_str());
}

String Network::httpGET(String url) {
  String payload="";
  // wait for WiFi connection
  if (WiFiMulti.run() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    if (NETWORK_DEBUG) {
      Serial.print("[Network] HTTP: begin...\n");
    }
    if (http.begin(client, url)) {  // HTTP
      if (NETWORK_DEBUG) {
        Serial.print("[Network] HTTP: GET...\n");
      }
      // start connection and send HTTP header
      int httpCode = http.GET();
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        if (NETWORK_DEBUG) {
          Serial.printf("[Network] HTTP: GET... code: %d\n", httpCode);
        }
        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          payload = http.getString();
          if (NETWORK_DEBUG) {
             Serial.println("[Network] HTTP: GET received msg: "+payload);
          }
        }
      } else {
        if (NETWORK_DEBUG) {
           Serial.printf("[Network] HTTP: GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
      }
      http.end();
    } else {
      if (NETWORK_DEBUG) {
        Serial.printf("[Network] HTTP: Unable to connect\n");
      }
    }
  }
  return payload;
}

