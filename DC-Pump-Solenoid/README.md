# Control a DC pump from Unity

In this project we are going to use Solenoid Relay to control a DC pump from Unity.First we will check the outpust of solenoid to find out which two pins we should use as outputs. Then we will turn the pump on and off with 2 second intervals.
Finally using Ardity (tutorial can be found <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Ardity">here</a>) we can control the pump by keyboard in Unity.

## check solenoid outputs

1- Wiring...

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/arduino-solenoid.jpg" width="700"/>

2- Code...

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

Note: After compiling and running the code the solenoid led must turn on.


3- Checking Resistance and current of solenoid outputs...

Using Voltmeter/Ohmmeter we can find aout which 2 pins of solenoid we can use as outputs (the one that have current when the solenoid is on). As the below gif shows (using Ohmmeter) if the resistance is zero it means there is current in the circuit and if the resistance value is '1' it means there is no current.

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/check-current.gif" width="700"/>
