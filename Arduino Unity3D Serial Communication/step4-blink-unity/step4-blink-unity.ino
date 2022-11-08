int ledPin = 12;

void setup() {
// initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  Serial.write(1);
  Serial.flush();
  delay(1000); // wait for a second
  digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  Serial.write(2);
  Serial.flush();
  delay(1000); // wait for a second
}