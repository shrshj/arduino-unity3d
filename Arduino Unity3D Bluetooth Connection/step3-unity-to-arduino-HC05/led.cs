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
