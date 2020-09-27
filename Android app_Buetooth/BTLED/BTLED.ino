#include <SoftwareSerial.h>
 
SoftwareSerial BT(10, 11); // rx, tx
int led = 13;
char val;
 
void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  BT.begin(9600);
  pinMode(led, OUTPUT);
}
 
void loop() {
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
    if(val == 'T'){
      digitalWrite(led, HIGH);
    }
    else if(val == 'F'){
      digitalWrite(led, LOW);
    }
  }
}
