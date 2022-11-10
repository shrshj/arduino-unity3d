In this section we will learn how to control an led using Blynk application (with phone) over wifi.<br />
The Circuit we used is like what we had <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Arduino%20Unity3D%20Serial%20Communication">here</a> with different output pin.

## Requirements
- Installing Blynk on IOS or Android phone and creating a device in it
- Installing Blynk library in Arduino IDE (<a href ="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/Blynk-install.png">Help</a>)
- Wifi connection between our phone and ESP32


## How to create a device on Blynk app?


<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/1.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/2.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/3.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/4.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/5.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/6.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/7.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/8.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/9.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/10.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/11.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/12.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/13.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/14.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/15.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/16.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/17.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/18.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/19.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/20.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/21.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/22.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/23.jpg" width="300"/><br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/24.jpg" width="300"/><br />


## How to access the App in the code?

Log-in to your blynk dashboard in PC and after selecting the right device go to device info tab and copy-paste it into the code.

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/device-info.png" width="900"/><br />


## Codes 

In the code below, after necessary device information we need to import requred libraries and also username and password of local wifi. The main part of this code is "BLYNK_WRITE" which helps us to access Virtual pin (button) we defined in the Blynk app. Based on the value of this virtual pin we can decide what can happen to a pin in ESP32.


```

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLxexYg_oz"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "q0wAXhdIfF0VrpyhI2huPJRFwKcksGgC"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PDIWindow";
char pass[] = "cdtcdtcdt";

// Select your pin with physical button
int pin = 21;
int value = 0;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pin, OUTPUT);
}

BLYNK_WRITE(V1)
{   
  value = param.asInt(); // Get value as integer
  if(value){
    digitalWrite(pin, HIGH);
  }
  else{
    digitalWrite(pin, LOW);
  }
}

void loop()
{
  Blynk.run();
}

```


## Results...

- When the button is off, in the mobile app:
<p>
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/OFF.jpg" width="300"/>
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/OFF-LED.jpg" width="300"/><br />
</p>


- When the button is on, in the mobile app:
<p>
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/ON.jpg" width="300"/>
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/ESP32%20and%20Unity3D%20wifi%20Connection/-media/ON-LED.jpg" width="300"/><br />
</p>

## Important Links

- <a href="https://docs.blynk.io/en/blynk.edgent-firmware-api/virtual-pins"> Controling Virtual Pins</a>
- <a href="https://www.instructables.com/Use-ESP32-to-Control-LED-With-Blynk-Via-WiFi/"> Useful Video Tutorial 1</a>
- <a href="https://www.patreon.com/posts/25890704"> Useful Video Tutorial 2</a>
- <a href="https://www.youtube.com/watch?v=rlqOXZqDsts"> Useful Video Tutorial 3</a>

