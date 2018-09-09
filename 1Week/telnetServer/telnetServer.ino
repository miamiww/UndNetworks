#include <ESP8266WiFi.h>
#include "wifi_secrets.h"

#define MAX_SRV_CLIENTS 1
WiFiServer server(23);
WiFiClient serverClients[MAX_SRV_CLIENTS];

void setup()
{  
  delay(500);
  // Begin serial connection at 9600 baud
  Serial.begin(9600);
  
  // Connect to WiFi access point
  bool stationConnected = WiFi.begin(
  SECRET_SSID,
  SECRET_PASS);

  // Check if connection errors
  if(!stationConnected)
  {
    Serial.println("Error, unable to connect specified WiFi network.");
  }
   if(stationConnected)
  {
    Serial.println("Able to connect");
  }

    server.begin();
    server.setNoDelay(true);
    Serial.print("Ready! Use 'telnet ");
    Serial.print(WiFi.localIP());
    Serial.println(" 23' to connect");
}

void loop() {
  // put your main code here, to run repeatedly:

}
