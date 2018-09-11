#include <ESP8266WiFi.h>
#include "wifi_secrets.h"

WiFiClient socket;      // variable for the socket connection
const int port = 8080;
char host[] = "192.168.0.104";

#define trigPin 2 //D4
#define echoPin 0 //D3

#define trigPin2 5 //D1
#define echoPin2 4 //D2

#define LEDpin 13


void setup()
{  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(LEDpin, OUTPUT);
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

  //left right distance
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
  if (distance >= 8 && distance < 11) {
    varToSend = 'p';
  }
   if (distance >= 11 && distance <= 20) {
    varToSend = 'r';

  }
  if (distance > 20) {
    varToSend = 'p';
  }
  Serial.println(varToSend);


  //up down distance
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  Serial.print("left right distance: ");
  Serial.println(distance2);
  
  char varToSend2;
  if (distance2 < 8 && distance2 >= 0) {
    varToSend2 = 'd';
  }

  if (distance2 >= 8 && distance < 11) {
    varToSend2 = 'p';
  }
   if (distance2 >= 11 && distance2 <= 20) {
    varToSend2 = 'u';

  }
  if (distance2 > 20) {
    varToSend2 = 'p';
  }
  Serial.print("up down dist: ");
  Serial.println(distance2);

  while (socket.available()) {
    Serial.print("Got something");
    String input = socket.readString();
    Serial.print(input);
  }

  socket.print(varToSend);
  delay(30);
  socket.print(varToSend2);
  delay(100);

  if (socket.connected()) {   // if you connected,
      digitalWrite(LEDpin, HIGH);
      
  } else {

      digitalWrite(LEDpin, LOW);
  }
  
}


boolean login() {
  socket.connect(host, port);   // attempt to connect

  while (!socket.connected()) { // While not connected, try again
    delay(1000);
    if (socket.connected()) {   // if you connected,
      socket.print('n');  // say hello to the server
      socket.print("alden");
      Serial.println("socket connection successful");
      digitalWrite(LEDpin, HIGH);
      
    } else {
      // if not connected, try again:
      Serial.println("connection failed, trying again");
      socket.connect(host, port);
      digitalWrite(LEDpin, LOW);
    }
  }
}


