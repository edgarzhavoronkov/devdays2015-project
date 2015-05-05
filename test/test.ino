// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1, myservo2;                  
 
int pos = 0;    
 
void setup() 
{ 
  myservo1.attach(9);
  myservo2.attach(10);
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  
  {                                  
    myservo1.write(pos);              
    delay(15);                       
  } 
  for(pos = 180; pos>=1; pos-=1)     
  {                                
    myservo1.write(pos);              
    delay(15);                      
  } 
  
  delay(100);
  
  for(pos = 0; pos < 180; pos += 1)  
  {                                  
    myservo2.write(pos);              
    delay(15);                       
  } 
  for(pos = 180; pos>=1; pos-=1)     
  {                                
    myservo2.write(pos);              
    delay(15);                      
  }   
} 
