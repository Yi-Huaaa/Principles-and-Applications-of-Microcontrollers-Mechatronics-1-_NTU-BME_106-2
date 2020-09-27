#include <Servo.h>
#include <SoftwareSerial.h>
 
SoftwareSerial BT(8, 9); // rx, tx
Servo myservo;
int led = 13;
int trigPin = 11;
int echoPin = 10;
int servoPin = 6;
char val;

bool isOpen = 0;
bool preB = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  BT.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
}
 
void loop() {
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
    if(val == 'T'){
      digitalWrite(led, HIGH);
      myservo.write(180);
      isOpen = 1;
    }
    else if(val == 'F'){
      digitalWrite(led, LOW);
      myservo.write(90);
      isOpen = 0;
    }
  }
  int duration, dist;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;
  bool B = (dist > 30 && isOpen == 0);
  if(B == true && preB == false){
    BT.print('B');
    Serial.println("Break in!");
  }
  preB = B;
  delay(100);
}
