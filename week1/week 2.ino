1)

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Hello");
  
  lcd.setCursor(0,1);
  lcd.print("I2C LCD");
}
void loop()
{

}



2)

int buttonState = 0;
const int LED = 3;

void Setup()
{
 pinMode(2,INPUT);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 
}

void loop()
{
  buttonState=digitalRead(2);
  //for()
  while(buttonState ==LOW){
    digitalWrite(LED,LOW);
  delay(10);
}


3) 
int buttonState = 0;
const int LED = 3;

void Setup()
{
 pinMode(2,INPUT);
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 
}

void loop()
{
  buttonState=digitalRead(2);
  //for()
  while(buttonState ==LOW){
    digitalWrite(LED,LOW);
  delay(10);
}