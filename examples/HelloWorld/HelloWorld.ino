//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  // initialization of the lcd :
  #if defined(ARDUINO_SAM_DUE)
    // it's an Arduino DUE, let's specify that we prefer to use the second I2C bus (Wire1 instead of Wire) :
    lcd.begin(Wire1);
  #else
    // not an Arduino DUE => by default, we use the main I2C bus (Wire) :
    lcd.begin(); 
  #endif

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
}


void loop()
{
  // Do nothing here...
}