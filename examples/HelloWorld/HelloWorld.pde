//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27. You have to CHOOSE:
LiquidCrystal_I2C lcd(0x27,16,2);  //for a 16 chars and 2 line display
/*     OR
LiquidCrystal_I2C lcd(0x27,20,4);  //for a 20 chars and 4 line display
*/

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  
  /*   and, OPTIONALLY, just in the CASE of a 20X4 DISPLAY
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
  */
}

void loop()
{
}
