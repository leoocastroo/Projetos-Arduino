int led = 13;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10000);              // wait for 10 seconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(10000);              // wait for 10 seconds
}
