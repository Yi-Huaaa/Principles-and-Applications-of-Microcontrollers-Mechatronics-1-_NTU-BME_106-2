#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); // rx, tx
int leftS = 5;
int rightS = 6;
int directionF = 7;
int directionB = 8;
void setup(){
  Serial.begin(9600);
  BT.begin(9600);
}                                                                                                                                               
void loop (){
  if (BT.available()>0){
    char pp=BT.read();
    Serial.println(pp);
    switch(pp){
    case 'f':  //Forward
    Serial.println("f");
      forward();
    break;
    case 'b':  //Back0 
    Serial.println("B");
      backward();
    break;
    case 'l':  //Turn Left
    Serial.println("L");
      turnleft();
    break;
    case 'r':  //Turn Right
    Serial.println("R");
      turnright();
    break;
    case 's':  //Stop
      carstop();
    break;
    }
  }
}
void forward(){
  analogWrite(leftS,255);
  analogWrite(rightS,255);
  digitalWrite(directionF,HIGH);
  digitalWrite(directionB,LOW);
}
void backward(){
  analogWrite(leftS,255);
  analogWrite(rightS,255);
  digitalWrite(directionF,LOW);
  digitalWrite(directionB,HIGH);
}
void turnright(){
  analogWrite(leftS,0);
  analogWrite(rightS,255);
  digitalWrite(directionF,HIGH);
  digitalWrite(directionB,LOW);  
}
void turnleft(){
  analogWrite(leftS,255);
  analogWrite(rightS,0);
  digitalWrite(directionF,HIGH);
  digitalWrite(directionB,LOW);
}
void carstop(){
  analogWrite(leftS,0);
  analogWrite(rightS,0);
  digitalWrite(directionF,LOW);
  digitalWrite(directionB,LOW);
}
