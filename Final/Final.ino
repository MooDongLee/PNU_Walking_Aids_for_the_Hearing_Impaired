#include <SoftwareSerial.h>
int micpin=A0;
int micpin2=A1;
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
  int micvalue = ((analogRead(micpin)+analogRead(micpin2))*0.5);
  Serial.println(micvalue);
  BTSerial.println(micvalue*2.5);
  delay(100);
  int i;
  
 
if(micvalue>90 && micvalue<170) /* 70db */ {
    for (i=0; i<6 ; i++)  {
         analogWrite(motorPin,150);
         delay(50);
         analogWrite(motorPin,0);
         delay(50);
    }       
 }
    else if(micvalue>170) /* 78db */ {
    for (i=0; i<6 ; i++)  {
         analogWrite(motorPin,150);
         delay(500);
         analogWrite(motorPin,0);
         delay(50);
    }       
 }
   
   
} 
