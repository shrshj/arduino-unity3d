#include <SoftwareSerial.h>;
SoftwareSerial myConn(10,11); //rx,tx

void setup(){

  myConn.begin(9600);
}

void loop(){

  myConn.println({"1"});
  delay(1000);
  myConn.println({"2"});
  delay(1000);

} 