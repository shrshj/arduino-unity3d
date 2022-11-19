using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UDP_Client : MonoBehaviour
{

    void Start()
    {
        UDPTest();
    }


    void Update()
    {
        
    }


    void UDPTest()
    {
        UdpClient client = new UdpClient(5200);
        try
        {
            client.Connect("127.0.0.1", 5200);
            byte[] sendBytes = Encoding.ASCII.GetBytes("Hello, from the client");
            client.Send(sendBytes, sendBytes.Length);
            IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);
            byte[] receivedBytes = client.Receive(ref remoteEndPoint);
            string receivedString = Encoding.ASCII.GetString(receivedBytes);
            print("Message received from the server\n" + receivedString);
        }
        catch (Exception e)
        {
            print("Exception Thrown "+ e.Message);
        }
    }


}
