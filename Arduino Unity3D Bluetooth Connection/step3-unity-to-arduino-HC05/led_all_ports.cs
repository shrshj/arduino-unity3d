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
