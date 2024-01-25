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
