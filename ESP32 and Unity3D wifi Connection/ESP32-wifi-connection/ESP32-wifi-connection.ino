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
