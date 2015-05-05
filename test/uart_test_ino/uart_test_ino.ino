//FROM SITE
//www.customelectronics.ru/arduino-rabota-s-com-portom/

int val = '0';

void setup() {
        Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) 
  {
    val = Serial.read();
  }
  
    if (val=='1') {
      digitalWrite(13,HIGH); delay (100);
      digitalWrite(13,LOW); delay (100);
    }
    if (val=='0') {
      digitalWrite(13,HIGH); delay (500);
      digitalWrite(13,LOW); delay (500);
    }
}
