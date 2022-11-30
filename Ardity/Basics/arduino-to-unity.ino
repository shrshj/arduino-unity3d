unsigned long last_time = 0;
int i;
void setup(){
  Serial.begin(9600);
  i = 0;
}

void loop(){

  if(last_time < millis() - 2000){
    Serial.println(i);
    last_time = millis();
    i++;
  }
}