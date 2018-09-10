#include <ESP8266WiFi.h>
#include "wifi_secrets.h"

WiFiClient socket;      // variable for the socket connection
const int port = 8080;
char host[] = "192.168.0.104";

#define trigPin 2 //D4
#define echoPin 0 //D3

boolean isPresenceDetected = false;




void setup()
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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
  login();
}

void loop(){

}


boolean login() {
  socket.connect(host, port);   // attempt to connect

  while (!socket.connected()) { // While not connected, try again
    delay(1000);
    if (socket.connected()) {   // if you connected,
      socket.println("hello");  // say hello to the server
      Serial.println("socket connection successful");
    } else {
      // if not connected, try again:
      Serial.println("connection failed, trying again");
      socket.connect(host, port);
    }
  }
}
