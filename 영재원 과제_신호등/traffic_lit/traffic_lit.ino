#include <Wire.h>
#include <Servo.h>
#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1);
byte go[] = {B00011000,B00010100,B11110010,B00000001,B00000001,B11110010,B00010100,B00011000};
byte red[] =  {B00111100,B01000010,B10100001,B10010001,B10001001,B10000101,B01000010,B00111100};
  int tlit[] = {2,3,4};//신호등 led
  int garo[] = {6,7};// 가로등 led
  int ybut = 8; //노란버튼
  int gbut = 9;//초록버튼
  Servo ns;  
  int pos = 0;  
void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  Serial.begin(9600);
  ns.attach(5);
  pinMode(ybut, INPUT);
  pinMode(gbut,INPUT);
  pinMode(garo[0],OUTPUT);
  pinMode(garo[1],OUTPUT);
  for(int i=0;i<=2;i++) pinMode(tlit[i],OUTPUT);
}
void loop() { 
  if(digitalRead(ybut)==1)
  {
    
    ns.write(90); 
    //Serial.println("파란불 보행가능\n");  
    for(int i=7;i>=1;i--) 
    {
      display_go();
    
      //Serial.print(i);
     // Serial.print("초\n");
      delay(1000);
    }
    }
  else
  { 
 display_red();
 ns.write(15);
 //Serial.println("빨간불 보행금지\n");
 delay(500);
  }  

/* Serial.print(digitalRead(ybut));
 delay(100);*/
}
void display_go()
{
    for (int o = 0; o < 8 ; o++)
    {
      lc.setRow(0, o, go[o]);
    }
}
void display_red()
{
      for (int p = 0; p< 8 ; p++)
    {
      lc.setRow(0, p, red[p]);

    
    }
}
