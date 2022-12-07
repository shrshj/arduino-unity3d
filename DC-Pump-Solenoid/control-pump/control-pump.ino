int pump = 13;
bool pumpState = false;
unsigned long last_feedback_time = 0;
void setup(){

  Serial.begin(9600);
  pinMode(pump,OUTPUT);
}

void loop(){
  if (Serial.available()){
    char c = Serial.read();
    if(c=='A'){
      digitalWrite(pump, HIGH);
      pumpState = true;
    }
    else if (c=='Z'){
      digitalWrite(pump, LOW);
      pumpState = false;
    }

  }

  if(last_feedback_time + 2000 < millis()){
    if(pumpState){
      Serial.println("Pump is ON");
    }
    else{
      Serial.println("Pump is OFF");
    }

  }





}