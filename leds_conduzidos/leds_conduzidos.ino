void setup() {
  for(int i=0;i<10;i++){
    pinMode(i+3,OUTPUT);  
  }
}

void loop() {
  for(int i=0;i<10;i++){
    digitalWrite(i+3,HIGH);
    delay(500);
  }

  for(int i=0;i<10;i++){
    digitalWrite(i+3,LOW);
    delay(500);
  }
}
