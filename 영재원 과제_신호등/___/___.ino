#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
  int tlit[] = {2,3,4};
  int ybut = 8;
  int gbut = 9;
  Servo myservo;  
  int pos = 0;  
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(ybut, INPUT);
}
void loop() {
  if(digitalRead(ybut)==HIGH)
  {
    myservo.write(90); 
    Serial.println("파란불 보행가능\n");
    for(int i=7;i>=1;i--) 
    {
      Serial.print(i);
      Serial.print("초\n");
      delay(1000);
    }
    }
  else
  { 
 myservo.write(15);
 Serial.println("빨간불 보행금지\n");
  }  

/* Serial.print(digitalRead(ybut));
 delay(100);*/
}
