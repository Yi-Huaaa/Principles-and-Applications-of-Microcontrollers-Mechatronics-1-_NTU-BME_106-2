int segment7[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int Bottun[3], mode, count, t[2], laststate;
unsigned long long int stime;
void Display(int number)
{   int digit[2];
    digit[0] = number % 10;
    digit[1] = number / 10;
    for(int i = 0; i < 2; i++)
          for(int j = 0; j < 7; j++)
            pinMode(7*i+j+2, segment7[digit[i]][j]);}
void setup() {
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  for(int i = 2; i <= 15; i++)
      pinMode(i, OUTPUT);
  mode = 0;
  count = 0;
  t[1] = 60;
  laststate = 60;}
void loop() {
    for(int i = 0; i < 3; i++)
         Bottun[i] = digitalRead(i + 16);
    if(Bottun[0] == HIGH)
    {mode = !mode;
     delay(500);}
    if(mode && Bottun[1] == HIGH)
    {if(count)
    laststate = t[1];
    else
    stime = millis();
        count = !count;
        delay(500); }
    if(mode!=0 && !count && Bottun[2] == HIGH)
    {   t[1] = 60;
        laststate = 60;
        delay(500);}
    t[0] = (millis()/1000) % 60;
    if(count)
     {  if(t[1] > 0)
        t[1] = laststate - (millis() - stime)/1000;
        else
        {  t[1] = 0;
           count = !count;}}
   ( mode == 0) ? Display(t[0]) : Display(t[1]);}
