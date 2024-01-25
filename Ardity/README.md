# Ardity

## Setup

- It is recommended to install Ardity from Git (download and import it as a custom package from the Assets tab) rather than from the Asset Store.
- While I faced some COM port issues on my PC, it worked smoothly on another PC.
- Main Git repository can be found [here](https://ardity.dwilches.com/).
- LED on/off Tutorial: [YouTube Link](https://www.youtube.com/watch?v=SD3iUnLNjY0)
- Guide to setup a project: [Setup Guide](https://github.com/dwilches/Ardity/blob/master/UnityProject/Ardity%20-%20Setup%20Guide.pdf)
- Note: When uploading .ino code to Arduino, ensure your Unity project is not running.

After following the setup guide (above link), compile and upload the provided Arduino code. In this code, Arduino sends an integer counter (or a string message) to Unity. On the Unity side, the Message Listener (OnMessageArrived() method) receives the message and stores it in a public variable for potential use.

### Arduino Code:

<br />
```
// arduino-to-unity/arduino-to-unity.ino

unsigned long last_time = 0;
int i;
void setup(){
  Serial.begin(9600);
  i = 0;
}

void loop(){

  if(last_time < millis() - 2000){
    Serial.println(i);
    last_time = millis();
    i++;
  }
}
```

<br />

### Unity Code:
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MyMessageListener : MonoBehaviour {

    // Use this for initialization

    public string MyMSG;
    void Start () {
    }
	
    // Update is called once per frame
    void Update () {

    }

    // Invoked when a line of data is received from the serial device.
    void OnMessageArrived(string msg)
    {
        Debug.Log("Arrived: " + msg);
        MyMSG = msg;
    }

    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }
}

```

## LED on-off Using keyboard (Digital input/output)
In this section, demo scenes available in Ardity are used. The script "Ardity/Scripts/Samples/SampleUserPolling_ReadWrite.cs" is essential. It reads a char from the keyboard (A or Z) and sends it to Arduino. Based on the value, it changes the LED status (on or off). Simultaneously, Arduino sends the LED status to Unity every 2 seconds.<br />

In Unity, select "Ardity/Scenes/DemoScene_UserPoll_ReadWrite.unity" and run the project. Press 'A' or 'Z'. In the Unity console, you will see a message saying "Sending A" or "Sending Z".<br />

### Unity Code:
```
using UnityEngine;
using System.Collections;

/**
 * Sample for reading using polling by yourself, and writing too.
 */
public class SampleUserPolling_ReadWrite : MonoBehaviour
{
    public SerialController serialController;

    // Initialization
    void Start()
    {
        serialController = GameObject.Find("SerialController").GetComponent<SerialController>();

        Debug.Log("Press A or Z to execute some actions");
    }

    // Executed each frame
    void Update()
    {
        //---------------------------------------------------------------------
        // Send data
        //---------------------------------------------------------------------

        // If you press one of these keys send it to the serial device. A
        // sample serial device that accepts this input is given in the README.
        if (Input.GetKeyDown(KeyCode.A))
        {
            Debug.Log("Sending A");
            serialController.SendSerialMessage("A");
        }

        if (Input.GetKeyDown(KeyCode.Z))
        {
            Debug.Log("Sending Z");
            serialController.SendSerialMessage("Z");
        }


        //---------------------------------------------------------------------
        // Receive data
        //---------------------------------------------------------------------

        string message = serialController.ReadSerialMessage();

        if (message == null)
            return;

        // Check if the message is plain data or a connect/disconnect event.
        if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_CONNECTED))
            Debug.Log("Connection established");
        else if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_DISCONNECTED))
            Debug.Log("Connection attempt failed or disconnection detected");
        else
            Debug.Log("Message arrived: " + message);
    }
}

```


<br />

### Arduino Code:
```
// led-on-off.led-on-off.ino

int ledPin = 13;
bool ledState = false;


void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  if(Serial.available()){

    char c = Serial.read();
    if(c){
    
      if(c=='A'){
        digitalWrite(ledPin,HIGH);
        ledState = true;
      }
      else if(c=='Z'){
        digitalWrite(ledPin,LOW);
        ledState = false;
      }
    }

  }

  if(ledState){
    Serial.println("led is ON");
  }
  else{
    Serial.println("led is OFF");
  }
  delay(1000);

}
```


<br />

### Demo
<img src="media/demo.gif" width="700"/>
