#include <SoftwareSerial.h>
int micpin=A0;
int motorPin = 11;
int micvalue = 0;
SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX)
byte buffer[1024]; // 데이터를 수신 받을 버퍼
int bufferPosition; // 버퍼에 데이타를 저장할 때 기록할 위치
void setup(){
  BTSerial.begin(9600); 
  Serial.begin(9600); 
  bufferPosition = 0; // 버퍼 위치 초기화
}
void loop(){
  int micvalue = analogRead(micpin);
  Serial.println(micvalue);
  BTSerial.println(micvalue);
  delay(100);
  int i;
  
 
  if(micvalue>150 && micvalue<250) /* 60db */ {
    for (i=0; i<2 ; i++)  {
         analogWrite(motorPin,50);
         delay(500);
         analogWrite(motorPin,0);
         delay(500);
    }       
 }
    else if(micvalue>250 && micvalue<350) /* 60db */ {
    for (i=0; i<4 ; i++)  {
         analogWrite(motorPin,100);
         delay(200);
         analogWrite(motorPin,0);
         delay(200);
    }       
 }
    else if(micvalue>350 && micvalue<450) /* 60db */ {
    for (i=0; i<4 ; i++)  {
         analogWrite(motorPin,100);
         delay(150);
         analogWrite(motorPin,0);
         delay(100);
    }       
 }
    else if(micvalue>450) /* 71db */ {
    for (i=0; i<10 ; i++) {
         analogWrite(motorPin, 255);
         delay(50);
         analogWrite(motorPin, 0);
         delay(50);
    }
  }
} 



