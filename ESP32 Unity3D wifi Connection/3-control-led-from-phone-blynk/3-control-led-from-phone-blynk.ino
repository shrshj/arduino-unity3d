
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL2yHQ0j9-"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "8Vonw-ftn3PV9_VpBs1fo8pwXHSGR_WR"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PDIWindow";
char pass[] = "cdtcdtcdt";

// Select your pin with physical button
int pin = 21;
int value = 0;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pin, OUTPUT);
}

BLYNK_WRITE(V1)
{   
  value = param.asInt(); // Get value as integer
  if(value){
    digitalWrite(pin, HIGH);
  }
  else{
    digitalWrite(pin, LOW);
  }
}

void loop()
{
  Blynk.run();
}
