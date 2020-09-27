#include "pitches.h" 
int a[]={A0,A1,A2,A3,A4,A5,2};
int melody[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4 };
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);}

void loop() {
  int buttonState = 0;
 for(int i= 0; i< 7; i++){
  buttonState = digitalRead(a[i]);
 if (buttonState == LOW) {
   tone(3,melody[i],100);}}}




   /*
   #include "pitches.h"
int a [] = {A0,A1,A2,A3,A4,A5,2};
int melody[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4 };
void setup() {
Serial.begin(9600);
    for(int i = 0; i<6 ;i++)
      pinMode (Ai, INPUT);
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    }

void loop() {
  int buttonstate = 0;
  for (int i = 0; i <6 ; i++) {
     buttonstate = digitalWrite (a[i]);
      if (buttonstate == LOW)
        tone(3,melody[i],100);
    }}
    */

