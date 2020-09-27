int leftgo=11 , leftback=10, rightgo= 6, rightback= 5, leftspeed=90, rightspeed=100, v0, v1,v2,v3, stat =1;

void setup() {
  Serial.begin(9600);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    analogWrite(leftback, 0);
    analogWrite(rightback, 0);
    stat = 1;
    }

void TurnR(int t)
{
    analogWrite(leftgo, leftspeed);
    analogWrite(rightgo, 0);
    delay(t);
}
void TurnL(int t)
{
    analogWrite(leftgo, 0);
    analogWrite(rightgo, rightspeed);
    delay(t);
}
void straight(int t)
{
    analogWrite(leftgo, leftspeed);
    analogWrite(rightgo, rightspeed);
    delay(t);
}

void S( int t){
    analogWrite(leftgo, 0);
    analogWrite(rightgo, 0);
    delay(t);
}
void loop() {
    //test for black line
    v0 = analogRead(A0);
    v1 = analogRead(A1);
    v2 = analogRead(A2);
    v3 = analogRead(A3);
    Serial.print(v0);
     Serial.print("--");
    Serial.print(v1);
    Serial.print("--");
    Serial.print(v2);
    Serial.print("--");
    Serial.print(v3);
    
    
    char c = 'A';
    switch(c){
      case 'A':
             v3>800;
             TurnL (3);
             Serial.println("LEFT");
             break;
      case 'B':
            v1>800;
            TurnR (3);
            Serial.println("LEFT");
            break;
      case 'C':
            straight(3);
            Serial.println("straight"); 
            break;
      case 'D':
            v0 > 700;
            S(2000); // control motor to not get away, before it turns
            TurnL(1000);
            straight(1500);
            TurnR(1400);
            straight(1700);
            TurnR(1400); 
            straight(1200);
            TurnL(1000);
            break ;
      }
    
    
    
    /*if(stat == 1)
    {
        if(v3 > 800)
        {
            TurnL(3);
            Serial.println("LEFT");
        }
        else if(v1 > 800)
        {
            TurnR(3);
            Serial.println("RIGHT");            
        }
        else
        {
           straight(3);
           Serial.println("straight");           
        }
        
        
    }
    
    if(v0 > 700)
        {     
              S(2000); // control motor to not get away, before it turns
              TurnL(1000);
              straight(1500);
              TurnR(1400);
              straight(1700);
              TurnR(1400); 
              straight(1200);
              TurnL(1000);
              break ;          
        }
   */


   
}

  
/*  
      右輪前轉 5
      右輪後轉 6
      左輪前轉 11
      左輪後轉 10
 */

