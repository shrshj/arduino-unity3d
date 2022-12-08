# Control a DC pump from Unity

In this project we are going to use Solenoid Relay to control a DC pump from Unity.First we will check the outpust of solenoid to find out which two pins we should use as outputs. Then we will turn the pump on and off with 2 second intervals.
Finally using Ardity (tutorial can be found <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Ardity">here</a>) we can control the pump by keyboard in Unity.

## 1 - check solenoid outputs

Wiring...

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Ardity/Demo.gif" width="700"/>

Code...

```

int outpin = 13;

void setup(){
  Serial.begin(9600);
  pinMode(outpin,OUTPUT);
  digitalWrite(outpin,HIGH);
}

void loop(){
}

```

After compiling and running the code the solenoid led must turn on.


Checking Resistance and current of solenoid outputs...


<br />
