void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int c = 0; c<2; c++){
     Serial.print("l");
     delay(1);
  }
  
  for(int c = 0; c<2; c++){
     Serial.print("d");
     delay(1);
  }
  for(int c = 0; c<2; c++){
     Serial.print("r");
     delay(1);
  }
  for(int c = 0; c<2; c++){
     Serial.print("u");
     delay(1);
  }
}
