void setup() {
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);}
void loop() {
  forward(3300);
  s(1000);
  turn_L(850);
  s(1200);
  forward (1300);
  s(1000);
  turn_L(900);
  s(1200);
  forward2(3300);
  s(1200);
  turn_L(900);
  forward2(1300);
  s(1200);
  }

 void forward(int t){
  analogWrite(5,121);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,225);
  delay(t);}
 void turn_L(int t){
  analogWrite(11,100);
  analogWrite(5,0);
  analogWrite(10,0);
  analogWrite(6,0);
  delay(t);}
void s(int t){
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0);
  delay(t);}
 void forward2(int t){
  analogWrite(5,116);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,225);
  delay(t);}

  
/*  我的車子
      右輪前轉 5
      右輪後轉 6
      左輪前轉 11
      左輪後轉 10
    
    

    
 */

