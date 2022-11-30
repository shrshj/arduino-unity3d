



## Step 1
In these section we tried to send data to a Arduino from a mobile app over bluetooth, to check if the bluetooth module works properly. We used HC-05 bluetooth module and Arduino UNO. Also, using <a href="http://ai2.appinventor.mit.edu/">MIT APP Inventor</a> we created a simple LED ON/OFF app to control an LED using it.

<br />
Notes...
- Link to the tutorial we used --- > <a href="https://www.youtube.com/watch?v=aQcJ4uHdQEA"> HERE</a>
- To upload the complied code correctly to the Arduino, HC-05 must be disconnected from Arduino.
- Download the app from <a href="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/step1_HC05-connection-to-phone-bluetooth/Bluetooth.apk">HERE</a>.

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
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step1-app.JPG" width="700"/>

<br />
Connections...
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step1-details.jpg" width="700"/>




<br />
Demo...
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step1-bluetooth-hc05-demo.gif" width="700"/>


## Step 2
### Transfering data from Arduino to Unity over Bluetooth (HC05)

In this section we tried to transfer data from Arduino to unity. in arduino loop() we send "1" or "2" with one second intervals and in unity we change the ball color based on the vallue we receive.

<br />
Notes...
- First, pair HC-05 and you PC Bluetooth. Then in your PC Bluetooth setting find out the COM port that HC-05 is connected to. (the Outgoing port)
- Make sure that in Player setting API Compatibility level is ".net" version 4 (It may be mentiond as .NET Framework) and not the standard version.
- To Upload the compiled code to Arduino, first disconnect the HC-05 and after Uploading reconnect it.

<br />
Connections...
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step2-connections.jpg" width="700"/>


<br />
C# script...

```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System;

public class SerialCOM : MonoBehaviour
{
    // parameters
    private string port = "COM4";
    private int baudrate = 9600;

    private SerialPort sp;
    bool isStreaming = false;
    public GameObject sphere;


    // Start is called before the first frame update
    void Start()
    {
        Open();

    }

    // Update is called once per frame
    void Update()
    {
        if (isStreaming)
        {
            string value = ReadSerialPort();

            if (value != null)
            {   
                Debug.Log(value);


                if (value.Equals("1"))
                {
                    // change ball color to blue
                    print("blue");
                    sphere.GetComponent<Renderer>().material.color = Color.blue;

                }
                else if (value.Equals("2"))
                {
                    // change ball color to red
                    print("red");
                    sphere.GetComponent<Renderer>().material.color = Color.red;

                }
                else
                {
                    print(value + " Not Numeric!!!");
                }
            }
            else
            {
                print("Null Value!!!!!!");
            }





        }
    }


    public void Open()
    {
        isStreaming = true;
        sp = new SerialPort(port, baudrate);
        sp.ReadTimeout = 100;
        sp.Open();
        Debug.Log("Port was opened successfully");

    }

    public string ReadSerialPort(int timeout = 50)
    {
        string message;
        sp.ReadTimeout = timeout;
        try
        {
            message = sp.ReadLine();
            Debug.Log(message);
            return message;
        }
        catch (TimeoutException)
        {
            return null;
        }
    }

    public void Close()
    {
        sp.Close();
    }
}


```

<br />
Arduino Code...

```
#include <SoftwareSerial.h>;
SoftwareSerial myConn(10,11); //rx,tx

void setup(){

  myConn.begin(9600);
}

void loop(){

  myConn.println({"1"});
  delay(1000);
  myConn.println({"2"});
  delay(1000);

} 
```

<br />
Demo...
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step2-demo.gif" width="700"/>


## Step 3
### Transfering data Unity to Arduino over Bluetooth (HC05)
In this step we tried to control an LED from Unity MRTK project. We have two ON/OFF buttons from Mixed Reality Toolbox (make sure to install mixed reality toolbox when adding mrtk to your project). First we need to pair HC-05 with the PC Bluetooth (Check step 2 for more details). 

<br />
In "led.cs" we only used COM4 port which we knew HC05 is connected to. But in hololens we coud not find out the port name. So instead using "led_all_ports.cs" we checked all the ports and tried to send data to all of them, however it was unsuccessful. 
<br />

Notes...
- In Unity create a controller (and drag led.cs into it). Then after creting MRTK button (from mrtk toolkit) in 
- <a href="https://www.youtube.com/watch?v=EIpxXodmO6A">This</a> video can help in creating MRTK Buttons.


<br />
C# script...

 ```
// led.cs

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;


public class led : MonoBehaviour
{
    // Start is called before the first frame update

    public SerialPort serial;
    private bool lightstate;

    void Start()
    {
        serial = new SerialPort("COM4", 9600);
        lightstate = false;

    }

    // Update is called once per frame
    public void on_led()
    {
        if(serial.IsOpen == false)
        {
            serial.Open();
        }
        serial.Write("A");
        lightstate = true;
    }

    public void off_led()
    {
        if (serial.IsOpen == false)
        {
            serial.Open();
        }
        serial.Write("B");
        lightstate = false;
    }
}


 ```


```
// led_all_ports.cs


using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System;

public class led1 : MonoBehaviour
{
    // Start is called before the first frame update

    public SerialPort[] serials;
    private bool lightstate;

    void Start()
    {
        lightstate = false;
        string[] ports = SerialPort.GetPortNames();
        serials = new SerialPort[ports.Length];

        int i = 0;
        foreach (string port in ports)
        {
            serials[i] = new SerialPort(port, 9600);
            i++;
        }


    }

    // Update is called once per frame
    public void on_led1()
    {
        for (int i = 0; i < serials.Length; i++)
        {
            try
            {
                if (!serials[i].IsOpen)
                {
                    serials[i].Open();
                }
                serials[i].Write("A");
                lightstate = true;
                print("Successful");
                print(serials[i].PortName);
            }
            catch (Exception e)
            {
                print("Unsuccessful");
                print(serials[i].PortName);
            }
        }
    }

    public void off_led1()
    {

        for (int i = 0; i < serials.Length; i++)
        {
            try
            {
                if (!serials[i].IsOpen)
                {
                    serials[i].Open();
                }
                serials[i].Write("B");
                lightstate = false;
                print("Successful");
                print(serials[i].PortName);
            }
            catch (Exception e)
            {
                print("Unsuccessful");
                print(serials[i].PortName);

            }
        }
    }
}

```

<br />
Arduino code...

```
// Control_Arduino_with_Unity.ino

int data;
#include <SoftwareSerial.h>;
SoftwareSerial myConn(10,11); //rx,tx

void setup(){
    myConn.begin(9600);
  pinMode(13,OUTPUT);
}
void loop(){
  if(myConn.available()){
    data = myConn.read();
    if(data == 'A'){
      digitalWrite(13,HIGH);
    }
    else {
      digitalWrite(13,LOW);
    }
  }
}

```


<br />
Demo...
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20Unity3D%20Bluetooth%20Connection/-media/step3-demo.gif" width="700"/>

