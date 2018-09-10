#include <ESP8266WiFi.h>
#include "wifi_secrets.h"

WiFiClient socket;      // variable for the socket connection
const int port = 8080;
char host[] = "192.168.0.104";

#define trigPin 2 //D4
#define echoPin 0 //D3


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

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.println(distance);
  delay(100);
  
  char varToSend;
  if (distance < 8 && distance >= 0) {
    varToSend = 'l';
  }
   if (distance >= 8 && distance <= 20) {
    varToSend = 'r';

  }
  if (distance > 20) {
    varToSend = 'p';
  }
  Serial.println(varToSend);

  while (socket.available()) {
    Serial.print("Got something");
    String input = socket.readString();
    Serial.print(input);
  }

  socket.print(varToSend);

  
}


boolean login() {
  socket.connect(host, port);   // attempt to connect

  while (!socket.connected()) { // While not connected, try again
    delay(1000);
    if (socket.connected()) {   // if you connected,
      socket.print('d');  // say hello to the server
      Serial.println("socket connection successful");
    } else {
      // if not connected, try again:
      Serial.println("connection failed, trying again");
      socket.connect(host, port);
    }
  }
}


