



## Step 1
In these section we tried to send data to a Arduino from a mobile app over bluetooth, to check if the bluetooth module works properly. We used HC-05 bluetooth module and Arduino UNO. Also, using <a href="http://ai2.appinventor.mit.edu/">MIT APP Inventor</a> we created a simple LED ON/OFF app to control an LED using it.<br />

Notes...
- Link to the tutorial we used --- > <a href="https://www.youtube.com/watch?v=aQcJ4uHdQEA"> HERE</a> <br />
- To upload the complied code correctly to the Arduino, HC-05 must be disconnected from Arduino.

<br />

Codes...

```
char Incoming_value = 0;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);       
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1'){
      Serial.println("1");             
      digitalWrite(13, HIGH);
    } 
    if(Incoming_value == '0'){
      Serial.println("0");       
      digitalWrite(13, LOW);
    }  
  }                            
}
```


<br />
App design...
<br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/app.JPG" width="700"/>

<br />
Connections...
<br />
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/details.jpg" width="700"/>




<br />
Demo...
<br />
https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/bluetooth-hc05-demo.mp4


