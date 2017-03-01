/**
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

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
  
  lcd.backlight();
  
  // Initialize the serial port at a speed of 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters received with the serial port 
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
