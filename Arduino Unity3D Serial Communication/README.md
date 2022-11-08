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


<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step2-blink-vid.gif" width="300"/>

## Step 3
Testing a blink code using a real LED (in a circuit)


```
// Arduino code
int ledPin = 12; // We can use Pin #2 to Pin #13 as the output pin

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
```

- Circuit 
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step3-blink-using-real-led-img.jpg" width="300"/>

- Result
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step3-blink-using-real-led-vid.gif" width="300"/>


## Step 4
Testing our blink code using Unity
- Note: becasue of heavy unity files Only the script file is uploaded here.
- Below pictures show the location of street lamp (downloaded from the assest store) and point light (added from GameObject)


<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step4-1.png" width="900"/>

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step4-2.png" width="900"/>

```
// Arduino code

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
```


```
// C# script connected to point light

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
public class flashing : MonoBehaviour
{
    public Light light_;
    SerialPort portNo = new SerialPort("COM4",9600);
    // Start is called before the first frame update
    void Start()
    {
        portNo.Open();
        portNo.ReadTimeout = 5000;
    }
    // Update is called once per frame
    void Update()
    {
        if (portNo.IsOpen)
        {
            try
            {
                blink_light(portNo.ReadByte());
            }
            catch (System.Exception)
            {
                throw;
            }
        }
    }
    void blink_light(int stat)
    {
        if (stat == 1)
        {
            light_.enabled = true;
            print(light_.enabled);
            print(1);
        }
        else if (stat == 2)
        {
            light_.enabled = false;
            print(light_.enabled);
            print(2);
        }
    }
}

```

- Result

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Serial%20Communication/-media/step4-3.png" width="900"/>