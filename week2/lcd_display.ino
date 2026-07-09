author piyusha sharma
IOT027
Summer School 26
  
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
