int ledPin = 13;
bool ledState = false;


void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  if(Serial.available()){

    char c = Serial.read();
    if(c){
    
      if(c=='A'){
        digitalWrite(ledPin,HIGH);
        ledState = true;
      }
      else if(c=='Z'){
        digitalWrite(ledPin,LOW);
        ledState = false;
      }
    }

  }

  if(ledState){
    Serial.println("led is ON");
  }
  else{
    Serial.println("led is OFF");
  }
  delay(1000);

}