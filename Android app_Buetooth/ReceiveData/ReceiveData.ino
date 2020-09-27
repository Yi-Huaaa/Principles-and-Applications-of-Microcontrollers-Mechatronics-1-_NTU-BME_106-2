#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); // rx, tx
void setup(){

  Serial.begin(9600);
  BT.begin(9600);
}
void loop (){
    byte Data[3];
    int i=analogRead(A0);
    int check=BT.read();
    Data[0]='A';
    Data[1]=i/256;
    Data[2]=i%256;
     Serial.println(check);
     if (check == 35){
         for(int j=0;j<3;j++)
          BT.write(Data[j]);
         check=0;
      } 
}
