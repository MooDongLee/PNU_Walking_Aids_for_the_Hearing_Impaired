#include <SoftwareSerial.h>
int micpin=A0;
int micpin2=A1;
int motorPin = 11;
int micvalue = 0;

void setup(){

  Serial.begin(9600); 

}
void loop(){
  int micvalue = (analogRead(micpin)+analogRead(micpin2))*0.5;
  Serial.println(micvalue);
  int i;
  
 
  if(micvalue>150 && micvalue<250) /* 60db */ {
    for (i=0; i<6 ; i++)  {
         analogWrite(motorPin,150);
         delay(200);
         analogWrite(motorPin,0);
         delay(200);
    }       
 }
    else if(micvalue>250 && micvalue<350) /* 60db */ {
    for (i=0; i<8 ; i++)  {
         analogWrite(motorPin,150);
         delay(50);
         analogWrite(motorPin,0);
         delay(50);
    }       
 }
    else if(micvalue>350 ) /* 60db */ {
    for (i=0; i<4 ; i++)  {
         analogWrite(motorPin,255);
         delay(500);
         analogWrite(motorPin,0);
         delay(50);
    }       
 }
   
} 
