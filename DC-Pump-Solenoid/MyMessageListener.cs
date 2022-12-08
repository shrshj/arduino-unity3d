using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MyMessageListener : MonoBehaviour {



    public string MyMSG;

    void OnMessageArrived(string msg)
    {
        Debug.Log("Arrived: " + msg);
        MyMSG = msg;
    }

    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }
}