# LiquidCrystal_I2C

## Description

This LiquidCrystal library helps the Arduino to control I2C displays with functions extremely similar to the LiquidCrystal library. This library might not be compatible with existing sketches.

## Installation

1. Navigate to the [Releases page](https://github.com/johnrickman/LiquidCrystal_I2C/releases).
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Functions

- oled_init()
- init()
- init_priv()
- begin()
- clear()
- home()
- setCursor()
- noDisplay()
- display()
- noCursor()
- cursor()
- noBlink()
- blink()
- scrollDisplayLeft()
- scrollDisplayRight()
- leftToRight()
- rightToLeft()
- autoscroll()
- noAutoscroll()
- createChar()
- noBacklight()
- backlight()
- command()
- send()
- write4bits()
- expanderWrite()
- pulseEnable()
- cursor_on()
- cursor_off()
- blink_on()
- blink_off()
- load_custom_character()
- setBacklight()
- printstr()

## Example

There are many examples implemented where this library is used. You can find other examples from [LiquidCrystak_I2C](https://github.com/johnrickman/LiquidCrystal_I2C/tree/master/examples)

One of the LiquidCrystal_I2C examples is the following:

- ### HelloWorld

```C++
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
void setup(){

    lcd.init();
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

void loop(){
}
```

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell others about this library
- Contribute new protocols

Please read [CONTRIBUTING.md](https://github.com/johnrickman/LiquidCrystal_I2C/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the   process for submitting pull requests to us.

## Credits

The author of this library is F. D. Brabander and it is maintained by M. Schwartz <marcolivier.schwartz@gmail.com>

Based on previous work by:

- M. Szafraniec
- Ortegafernando
- M. Perera
- J. Rickman
- C. Maglie
- Meridani
- C. Thomas
- P. Georges

This repo is being transfered to [GitLab](https://gitlab.com/tandembyte/liquidcrystal_i2c)