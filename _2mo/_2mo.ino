#include <SoftwareSerial.h>
int micpin=A0;
int motorPin = 11;
int motorPin2=10;
int micvalue = 0;

void setup(){
 
  Serial.begin(9600); 
  
}
void loop(){
  int micvalue = analogRead(micpin);
  Serial.println(micvalue);
  int i;
  if(micvalue>150 && micvalue<250) /* 60db */ {
    for (i=0; i<2 ; i++)  {
         analogWrite(motorPin,50);
         delay(500);
         analogWrite(motorPin2,0);
         delay(500);
         analogWrite(motorPin,0);
         delay(500);
         analogWrite(motorPin2,50);
         delay(500);
    }       
 }
    else if(micvalue>250 && micvalue<350) /* 60db */ {
    for (i=0; i<4 ; i++)  {
         analogWrite(motorPin,100);
         delay(200);
         analogWrite(motorPin2,0);
         delay(200);
         analogWrite(motorPin,0);
         delay(200);
         analogWrite(motorPin2,100);
         delay(200);
    }       
 }
    
        
 
    else if(micvalue>350) /* 71db */ {
    for (i=0; i<10 ; i++) {
         analogWrite(motorPin, 255);
         delay(50);
         analogWrite(motorPin2,0);
         delay(50);
         analogWrite(motorPin, 0);
         delay(50);
         analogWrite(motorPin2,255);
         delay(50);
    }
  }
} 
