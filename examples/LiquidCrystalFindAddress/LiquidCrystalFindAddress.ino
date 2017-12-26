/*
 * This sketch will loop through adresses until it sees an I2C device
 * When an address is found, we'll assume it's an Liquidcrystal I2C
 * display and show the address there as well as on Serial.
 * 
 * written by Jens Chr Brynildsen 2017 to help test 30 screens with
 * varying I2C addresses.
 */

//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0, 20, 4);
int address;
char buff[10];

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  delay(2000);

  for (address = 0; address <= 119; address++) {
    Wire.beginTransmission(address);
    int error = Wire.endTransmission();

    if (error == 0) { // device found
      sprintf(buff, "%02x", address);
      Serial.print("Address: ");
      Serial.println( buff );
      lcd.setAddress( address ); // set the address
      lcd.init();
      lcd.backlight();
      lcd.setCursor(0, 0);
      lcd.print("Hello world");
      lcd.setCursor(0, 1);
      lcd.print("I2C addr: 0x");
      lcd.setCursor(12, 1);
      lcd.print(buff);
      while (1);
    }
  }
}


void loop()
{
  // if we reach this point, nothing was found on the I2C bus
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN) );
  delay(100);
}
