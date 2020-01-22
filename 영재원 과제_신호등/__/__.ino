#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

byte go[] =
{B00011000,
B00010100,
B11110010,
B00000001,
B00000001,
B11110010,
B00010100,
B00011000};

byte red[] =
{B00111100,
B01000010,
B10100001,
B10010001,
B10001001,
B10000101,
B01000010,
B00111100};
  int b1 = 3;
   

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
  pinMode(b1,INPUT);
}
void loop() {

  display_go();
   delay(1000); 
  display_red();
  delay(1000);
  
}

void display_go()
{
    for (int i = 0; i < 8 ; i++)
    {
      lc.setRow(0, i, go[i]);
    
    }
}
void display_red()
{
      for (int i = 0; i < 8 ; i++)
    {
      lc.setRow(0, i, red[i]);
    
    }
}
