# Control a DC pump from Unity

In this project we are going to use Solenoid Relay to control a DC pump from Unity.First we will check the outpust of solenoid to find out which two pins we should use as outputs. Then we will turn the pump on and off with 2 second intervals.
Finally using Ardity (tutorial can be found <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Ardity">here</a>) we can control the pump by keyboard in Unity.

## check solenoid outputs

1- Wiring...

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/wiring-arduino-solenoid.jpg" width="700"/>

2- Code...

```
check_solenoid.ino
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


## Turn a DC pump ON and OFF with 2 second intervals

1- Wiring...

Try to make a triangle shape connection between Solenoid, Pump and, power suply (based on my experience no difference if we swap pos). I used a 9V power charger for power. 

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/wiring.jpg" width="700"/>

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/my-wiring.jpg" width="700"/>



2- Codes...

```
//check_solenoid.ino
int outpin = 13;

void setup(){
  Serial.begin(9600);
  pinMode(outpin,OUTPUT);
  digitalWrite(outpin,HIGH);
}

void loop(){
    digitalWrite(outpin,HIGH);
    delay(2000);
    digitalWrite(outpin,LOW);
    delay(2000);
}

```

3- Output...

<a href = "https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/dc-pump.mp4">Link</a> to the .mp4 format.

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/dc-pump.gif" width="700"/>


## Controlling the pump from Unity

1- Setup the Unity project as it is explained <a href = "https://github.com/shshjmakerspace/ArduinoUnity3D/tree/main/Ardity">HERE</a>.

2- Codes...

```
control-pump.ino
int pump = 13;
bool pumpState = false;
unsigned long last_feedback_time = 0;
void setup(){
  Serial.begin(9600);
  pinMode(pump,OUTPUT);
}

void loop(){
  if (Serial.available()){
    char c = Serial.read();
    if(c=='A'){
      digitalWrite(pump, HIGH);
      pumpState = true;
    }
    else if (c=='Z'){
      digitalWrite(pump, LOW);
      pumpState = false;
    }
  }

  if(last_feedback_time + 2000 < millis()){
    if(pumpState){
      Serial.println("Pump is ON");
    }
    else{
      Serial.println("Pump is OFF");
    }
  }
}

```
3- Demo...

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/demo.gif" width="700"/>
[![Watch the video](https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/demo-thumbnail.jpg)](https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/DC-Pump-Solenoid/-media/demo.gif)
