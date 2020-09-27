void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  forward(2000);
  s(800);
  turn_L(500);
  s(800);
  forward(4000);
  s(1000);
  back(2000);
  s(800);
  turn_L(700);
  s(800);
  forward(2000);
}
void forward(int t){
  analogWrite(5,67);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,120);
  delay(t);}
 void back(int t){
  analogWrite(5,0);
  analogWrite(6,80);
  analogWrite(10,120);
  analogWrite(11,0);
  delay(t);}
 void turn_L(int t){
  analogWrite(5,100);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0);
  delay(t);}
 void s(int t){
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0);
  delay(t);}

  
