void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  forward(2500);
  s(800);
  back(1500);
  s(800);
  turn_R(400);
  s(800);
  forward(1500);
  s(400);
  back(1500);
  s(800);
  turn_L(680);
  s(400);
  back(3000);
}
  
void forward(int t){
  analogWrite(5,73);
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
 void turn_R(int t){
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,100);
  delay(t);}
 void s(int t){
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0);
  delay(t);}

  

