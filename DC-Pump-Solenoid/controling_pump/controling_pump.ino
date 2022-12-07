int ledPin = 13;
bool ledState = false;
unsigned long last_msg_send = 0;

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

  if(last_msg_send < millis() - 3000){
    if(ledState){
      Serial.println("Motor is ON");
    }
    else{
      Serial.println("Motor is OFF");
    }
    last_msg_send = millis();
  }

}