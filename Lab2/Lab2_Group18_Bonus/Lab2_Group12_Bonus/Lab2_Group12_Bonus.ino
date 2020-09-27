
#define ASeg  8
#define BSeg  2
#define CSeg  9
#define DSeg  12
#define ESeg  11
#define FSeg  7
#define GSeg  4
int segs[7] = { ASeg, BSeg, CSeg, DSeg, ESeg, FSeg, GSeg };
int seven_seg_digits[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int Bottun[3], mode, count, t_min[2], t_sec[2], laststate_min, laststate_sec, order = 0;
unsigned long long int stime;
int reset()
{
  laststate_min = t_min[1] = 2;
  laststate_sec = t_sec[1] = 0;
}
int inverse(int t) { return t ? 0 : 1; }
void Display()
{
  int number;
  if(order < 2)
    number = t_min[mode];
  else
    number = t_sec[mode];
  if(order % 2 == 0)
    number = number / 10;
  else
    number = number % 10;
  for(int j = 0; j < 7; j++)
     pinMode(segs[j], seven_seg_digits[number][j]);
      //pinMode(segs[j], 0);
}

void setup() {
  Serial.begin(9600);
  /*
  pinMode ( ASeg , OUTPUT );
  pinMode ( BSeg , OUTPUT );  
  pinMode ( CSeg , OUTPUT );
  pinMode ( DSeg , OUTPUT );
  pinMode ( ESeg , OUTPUT );
  pinMode ( FSeg , OUTPUT );
  pinMode ( GSeg , OUTPUT );
  */
  for(int i = 0; i < 7; i++)
    pinMode(segs[i], OUTPUT);
  //for(int i = 2; i <= 15; i++)
  //    pinMode(i, OUTPUT);
  mode = 0;
  count = 0;
  reset();
  }
void loop() {    
    for(int i = 0; i < 3; i++)
         Bottun[i] = digitalRead(i + 16);
    //for testing
    if(Bottun[0] == HIGH)
      Serial.print("B0");
    if(Bottun[1] == HIGH)
      Serial.print("B1");
    if(Bottun[2] == HIGH)
      Serial.print("B2");


    if(Bottun[0] == HIGH)
    {mode = inverse(mode);
     delay(500);}
    if(mode && Bottun[1] == HIGH)
    {
      if(count)
      {
        laststate_min = t_min[1];
        laststate_sec = t_sec[1];
      }
       else
       stime = millis();
       count = !count;
       delay(500);
    }
    if(mode!=0 && !count && Bottun[2] == HIGH)
    {   
      reset(); 
      delay(500);
    }
     t_sec[0] = (millis()/1000) % 60;
     if(t_sec[0] == 0)
      t_min[0] = inverse(t_min[0]);
    if(count)
     {  if(t_sec[1] > 0)
        t_sec[1] = laststate_sec - (millis() - stime)/1000;
        else
        {  
          t_sec[1] = 0;
          if(t_min[1] > 0)
          {
            t_min[1]--;
            t_sec[1] = 59;
          }
           count = !count;
          }
        }

         //( mode == 0) ? Display(t[0]) : Display(t[1]);
         Display();
         order = (order + 1) % 4;
     } 
