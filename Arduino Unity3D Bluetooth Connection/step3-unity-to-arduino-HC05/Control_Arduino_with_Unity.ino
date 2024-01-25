int data;
#include <SoftwareSerial.h>;
SoftwareSerial myConn(10,11); //rx,tx

void setup(){
    myConn.begin(9600);
  pinMode(13,OUTPUT);
}
void loop(){
  if(myConn.available()){
    data = myConn.read();
    if(data == 'A'){
      digitalWrite(13,HIGH);
    }
    else {
      digitalWrite(13,LOW);
    }
  }
}
