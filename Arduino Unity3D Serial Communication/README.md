## Step 1
Preparing requirements for Arduino code
- Arduino IDE (version 2.0.1 for windows 10)
- Arduino Uno R3 Board
- USB cable to connect Arduino to the PC

## Step 2
Testing a simple blinking code on Arduino
- To do so we can use built-in led of Arduino which is connected to pin #13 in Uno R3. 
- Note: select the correct port and board model from tools menu.


```
// Arduino code
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
```
'''![Alt Text](https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/-media/step2-blink-vid.gif =250x250)'''

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/-media/step2-blink-vid.gif " width="250" height="250"/>
