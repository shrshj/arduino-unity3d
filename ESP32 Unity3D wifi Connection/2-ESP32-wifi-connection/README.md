The main purpose of this section is to check if ESP32 can connect to the wifi or not. Then we try to ping ESP32 from another device in the local network (For example a phone connected to the same wifi).<br />
- In Android we can use ConnectBot App to access terminal. Make sure to set protocol to "Local" and set your desired user name.
- To ping other devices from ESP32 we need to install "ESP32Ping" in Arduino IDE.

```
#include <WiFi.h>;
#include <ESP32Ping.h>;

bool pingsuccess = false;
char iptoping[] = "192.168.0.73"; // or url

const char* ssid = "PDIWindow";
const char* password =  "cdtcdtcdt";


void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  delay(2000);
  Serial.print("Connecting to WiFi");
 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println("\nConnected to the WiFi network.\n");


}
 
void loop() {
  if((WiFi.status() == WL_CONNECTED)){ //Check the current connection status
    Serial.println("\n------------------------------------------------------");
    Serial.println("You can try to ping me. My ip is...");
    Serial.println(WiFi.localIP());
    Serial.println("\n");

    Serial.println("I am also trying to ping below address...");
    Serial.println(iptoping);
    pingsuccess = Ping.ping(iptoping); // ip or url to ping by me
    Serial.println("\n");

    if(!pingsuccess){
      Serial.println("Ping failed");
    }
    else{
      Serial.println("Ping succesful.");
    }
    
    delay(10000);

  }
  else
  {
    Serial.println("Connection lost");
  }
}


```