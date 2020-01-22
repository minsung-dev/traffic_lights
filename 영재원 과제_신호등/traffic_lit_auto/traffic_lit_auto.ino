#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h>
#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1);
byte go[] = {B00011000,B00010100,B11110010,B00000001,B00000001,B11110010,B00010100,B00011000};
byte red[] =  {B00111100,B01000010,B10100001,B10010001,B10001001,B10000101,B01000010,B00111100};
  int tlit[] = {2,3,4};//신호등 led
  int garo[] = {6,7};// 가로등 led
  char s;
  Servo ns;  
  int pos = 0;  
void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  Serial.begin(9600);
  ns.attach(5);
  pinMode(garo[0],OUTPUT);
  pinMode(garo[1],OUTPUT);
  for(int i=0;i<=2;i++) pinMode(tlit[i],OUTPUT);
  Serial.println("명령을 입력하시오");
    lcd.init();
  lcd.backlight();
}
void loop() {
    lcd.setCursor(0,0);           
    lcd.print("--school  zone--"); 
    lcd.setCursor(0,1);
    lcd.print("   drive slow");
    if(Serial.available())
    {
      s = Serial.read();
      if(s == 'b'){
            Serial.println("학교 옆 신호등 : 파란불"); 
            digitalWrite(tlit[0],LOW);
            digitalWrite(tlit[1],LOW);
            digitalWrite(tlit[2],HIGH);
            Serial.print("학교 옆 신호등 :");
            Serial.print(7);
            Serial.print("초\n");
            delay(1000);
            for(int e=6;e>=2;e--)
            {
            Serial.print("학교 옆 신호등 :");
            Serial.print(e);
            Serial.print("초\n");
            delay(1000);
            }
            Serial.print("학교 옆 신호등 : 노란불\n");
            digitalWrite(tlit[0],LOW);
            digitalWrite(tlit[1],HIGH);
            digitalWrite(tlit[2],LOW);
            Serial.print("학교 옆 신호등 : 1초\n");
            delay(1000);
            Serial.println("학교 옆 신호등 : 빨간불");
                       
      }
            
       if(s == 'a')
      {
        ns.write(90); 
       Serial.println("학교 앞 신호등 : 파란불");
       Serial.println("차단기가 올라갑니다");  
          for(int i=7;i>=1;i--) 
         {
         display_go();  
           Serial.print("학교 앞 신호등 :");
             Serial.print(i);
            Serial.print("초\n");
            lcd.setCursor(0,0);
            lcd.print(" ");
            lcd.print(" ");
            lcd.print(i);
            lcd.print(" ");
            lcd.print("seconds left");
           delay(1000);
       }
       Serial.println("학교 앞 신호등 : 빨간불");
        Serial.println("차단기가 내려갑니다");
      }
      
    } 
  else
  { 
 digitalWrite(tlit[0],HIGH);
 digitalWrite(tlit[1],LOW);
 digitalWrite(tlit[2],LOW);
 delay(50);
 display_red();
 ns.write(15);
 delay(500);
  }  
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
