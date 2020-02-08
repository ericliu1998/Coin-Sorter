#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
const int coin1  = A2;
const int coin5 = A1;
const int coin10  = A3;
const int coin25  = A0; 

int ir1,ir5,ir10,ir25 = 0;
int cntr1,cntr5,cntr10,cntr25,cnttotal = 0;
int thres=900;
void setup() {
  Serial.begin(9600); 
  pinMode(coin1, INPUT);
  pinMode(coin5 ,INPUT);
  pinMode(coin10,INPUT);
  pinMode(coin25,INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  //int flag = 0;
  ir1 =digitalRead(coin1);  
  ir5 =digitalRead(coin5); 
  ir10=digitalRead(coin10);  
  ir25=digitalRead(coin25);

if(cntr1>99||cntr5>99||cntr10>99||cntr25>99){
  lcd.setCursor(10,3);
  lcd.print("Bin is full");
}
  
if(ir1==0){
  cntr1++;
  cnttotal++;
  delay(500);
}
if(ir5==0){
  cntr5++;
  cnttotal+=5;
  delay(500);
}
if(ir10==0){
  cntr10++;
  cnttotal+=10;
  delay(500);
}
if(ir25==0){
  cntr25++;
  cnttotal+=25;
  delay(500);
}

lcd.setCursor(0,0);
lcd.print("$0.01: ");
lcd.print(cntr1);
lcd.setCursor(0,1);
lcd.print("$0.05: ");
lcd.print(cntr5);
lcd.setCursor(0,2);
lcd.print("$0.10: ");
lcd.print(cntr10);
lcd.setCursor(0,3);
lcd.print("$0.25: ");
lcd.print(cntr25);
Serial.print(ir25);
Serial.print("\n");

lcd.setCursor(12,1);
lcd.print("Total:");
lcd.setCursor(12,2);
lcd.print(cnttotal);

//if(cnttotal==205){
//  lcd.setCursor(12,3);
//  lcd.print("passed");
//}else if(cnttotal>205){
//  lcd.setCursor(12,3);
//  lcd.print("failed");
//}
}
