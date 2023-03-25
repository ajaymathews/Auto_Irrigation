
#include <LiquidCrystal.h>
float MOISTURE,temp;
int x;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
 // pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  //digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  lcd.begin(16, 2);
  lcd.print("AUTO-IRRIGATION");
  lcd.setCursor(0,1);
  lcd.print("INITIALIZING...");
  delay(2000);
}

void loop() 
{
 x=analogRead(A0);//below 400:moisture  
 temp=float(abs(x-679));
 MOISTURE=((temp/400)*100);
 if(MOISTURE>100)
 {
   MOISTURE=100;
   
 }
 lcd.setCursor(0,0);
 lcd.print("AUTO-IRRIGATION");
 lcd.setCursor(0,1);
 lcd.print("MOISTURE:");
 lcd.setCursor(9,1);
 lcd.print(MOISTURE);
 lcd.println("%");
 if(MOISTURE<20)
 {
  digitalWrite(13,HIGH);
 }
 delay(3000);
 lcd.clear();
 digitalWrite(13,LOW);
}
