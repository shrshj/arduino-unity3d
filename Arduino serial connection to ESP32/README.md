## Importnat Notes
- Tutorial <a href="https://www.programmingboss.com/2021/04/esp32-arduino-serial-communication-with-code.html">Link</a>
- Boards: Arduino UNO R3, ESP-WROOM-32
- Conncet TX and RX of boards in a cross way. Also conncet GND pins of them.
Here, in ESP we defined Pin #16 as RX and Pin #17 as TX. In Arduino we used TX and RX defined on the board (Pin #1 and Pin #0).
- We need to provide two ino files, one for ESP and one for Arduino.
- Make sure that "serial baud rate" of both codes are same (here 9600). Using different baud rate can cause into reciving weired charachters in the Serial Monitor of Arduino IDE.
- For ESP code we need to download the ESP32 board on the IDE. This <a href="https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/">link</a> can help.
- One problem that can happen is that Arduino IDE may not recognize ESP32 port. If it happened first check if the usb cable can transfer data or not (it must be able to transfer the data). If the cable has no problem then it can be beacuse of usb-to-uart bridge driver. Fist check the version required for the ESP board (must be written on a tiny black matterial on the board like <a href="https://startingelectronics.org/articles/ESP32-WROOM-testing/">here</a>) and download it. For me it was cp2102 version. If you are using windows 10 or 11 most probably the problem is because of the cable (It was also my problem).

## Connections
<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20serial%20connection%20to%20ESP32/-media/conn.jpg" width="400"/>

## ESP32 code

```
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
```

## Arduino code

```
// this sample code provided by www.programmingboss.com
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println("Hello Boss");
  delay(1500);
}
```

## Result

<img src="https://github.com/shshjmakerspace/ArduinoUnity3D/blob/main/Arduino%20serial%20connection%20to%20ESP32/-media/res.JPG" width="900"/>

