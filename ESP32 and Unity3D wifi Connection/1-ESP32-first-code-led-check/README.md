
This code is just to check if we installed ESP32 on Arduino properly.<br />
The Circuit can be find <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Arduino%20Unity3D%20Serial%20Communication">here</a> but we used pin #21 instead of pin #12.

```

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
```