// this sample code provided by www.programmingboss.com
#define RXp2 16
#define TXp2 17
char msg[] = "Message Received";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
    Serial.println(msg);
    Serial.println(Serial2.readString());
}