#include <LiquidCrystal.h>
#include <stdlib.h>
const int rs = 12, en = 11, D4 = 6, D5 = 5, D6 = 4, D7 = 3;
const int buzzer = 13;
LiquidCrystal lcd(rs,en,D4,D5, D6, D7);
int sec = 0;
void setTime(int h, int m, int s){
  sec = (h*60*60)+(m*60)+s;
}
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  displayMsgAt("Promodoro Timer",0,0);
  setTime(0,1,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  displayTimer();
  delay(1000);
  if(sec==0){
    top:
    clearLine(0);
    noTone(buzzer);
    delay(1000);
    displayMsgAt("Time Over",0,0);
    tone(buzzer,1000);
    delay(1000);
    goto top;
  }
  sec--;
}
void displayMsgAt(char *s,int x, int y){
  lcd.setCursor(x,y);
  lcd.print(s);
}
void clearLine(int lineNo){
   for(int i=0;i<16;i++){
     displayMsgAt(" ",i,lineNo);
   }
}
void displayTimer(){
  
  int h = sec/(60*60);
  if(h<10){
    lcd.setCursor(1,1);
    lcd.print(" ");
  }
  lcd.setCursor(0,1);
  lcd.print(h);
  displayMsgAt(":",2,1);
  int m = (sec%(60*60))/60;
  if(m<10){
    displayMsgAt(" ",4,1);
  }
  lcd.setCursor(3,1);
  lcd.print(m);
  displayMsgAt(":",5,1);
  int s = sec%60;
  if(s<10){
    lcd.setCursor(7,1);
    lcd.print(" ");
  }
  lcd.setCursor(6,1);
  lcd.print(s);
}
