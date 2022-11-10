
// the setup function runs once when you press reset or power the board
int ledPin = 21;

void setup() {
  // initialize digital pin GIOP18 as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on
  delay(500);             // wait for 500 milliseconds
  digitalWrite(ledPin, LOW);  // turn the LED off
  delay(500);             // wait for 500 milliseconds
}