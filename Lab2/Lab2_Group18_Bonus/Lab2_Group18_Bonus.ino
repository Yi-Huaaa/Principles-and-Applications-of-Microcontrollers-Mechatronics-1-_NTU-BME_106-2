#define PIN_0 7
#define PIN_g 6
#define PIN_c 5
#define PIN_h 0
#define PIN_d 3
#define PIN_e 2
#define PIN_b 8
#define PIN_1 9
#define PIN_2 10
#define PIN_f 11
#define PIN_a 12
#define PIN_3 13
#define POS_NUM 4
#define SEG_NUM 8
const byte pos_pins[POS_NUM] = {PIN_0, PIN_1, PIN_2, PIN_3};
const byte seg_pins[SEG_NUM] = {PIN_a, PIN_b, PIN_c, PIN_d, PIN_e, PIN_f, PIN_g, PIN_h};

#define t true
#define f false
const boolean data[10][SEG_NUM] = {
  {t, t, t, t, t, t, f, f}, // 0
  {f, t, t, f, f, f, f, f}, // 1
  {t, t, f, t, t, f, t, f}, // 2
  {t, t, t, t, f, f, t, f}, // 3
  {f, t, t, f, f, t, t, f}, // 4
  {t, f, t, t, f, t, t, f}, // 5
  {t, f, t, t, t, t, t, f}, // 6
  {t, t, t, f, f, f, f, f}, // 7
  {t, t, t, t, t, t, t, f}, // 8
  {t, t, t, t, f, t, t, f}, // 9
};


//以下開始改code
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
     pinMode(seg_pins[j], data[number][j]);
      //pinMode(segs[j], 0);
}

//以上開始改code
void pf(const char *fmt, ... ){
    char tmp[128]; // max is 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(tmp, 128, fmt, args);
    va_end (args);
    Serial.print(tmp);
}

void setDigit(int pos, int n){
  if(pos < 0 || 3 < pos){
    pf("error pos=%d\n", pos);
    return;
  }

  for(int p = 0; p < POS_NUM; p++){
    if(p == pos)
      digitalWrite(pos_pins[p], HIGH);
    else
      digitalWrite(pos_pins[p], LOW);
  }
  

  if(0 <= n && n <= 9){
    for(int i = 0; i < SEG_NUM; i++){
      digitalWrite(seg_pins[i], data[n][i] == t ? LOW : HIGH);
    }
  }
  else{
    for(int i = 0; i < SEG_NUM; i++){
      digitalWrite(seg_pins[i], HIGH);
    }
    digitalWrite(PIN_h, LOW);
    pf("error pos=%d, n=%d\n", pos, n);
  }
}

void setNumber(int number)
{
  int n0, n1, n2, n3;
  n3 = number /600;
  n2 = number / 60;
  n2 = n2 % 10;
  n1 = number % 60;
  n1 = n1 / 10;
  n0 = number % 60;
  n0 = n0 % 10;

  setDigit(0, n0); delay(1);
  setDigit(1, n1); delay(1);
  setDigit(2, n2); delay(1);
  setDigit(3, n3); delay(1);
}

unsigned long time_previous;
void setup() {
  Serial.begin(115200);
  
  for(int i = 0; i < POS_NUM; i++){
    pinMode(pos_pins[i], OUTPUT);
    digitalWrite(pos_pins[i], LOW);
  }
  for(int i = 0; i < SEG_NUM; i++){
    pinMode(seg_pins[i], OUTPUT);
    digitalWrite(seg_pins[i], HIGH);
  }
  
  time_previous = millis();
}

int number = 0;
void loop() {
  unsigned long time_now = millis();
  if(time_now - time_previous > 1000){
    number++;
    time_previous += 1000;
    pf("number=%d\n", number);
  }

  setNumber(number);

  // 以下開始改code
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

 //以上開始改code
}

