//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

void setup(LiquidCrystal_I2C &lcd)
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
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
}

#if !defined(ARDUINO)

#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>

void usage(char *pgm)
{
    fprintf(stderr, "usage: %s [-a adapter][-d addr][-r rows][-c columns]\n", pgm);
    fprintf(stderr, "specify adapter in base 16, e.g., -a 27 for hex 0x27", pgm);
    _exit(1);
}

int main(int argc, char *argv[])
{
    extern char *optarg;
    extern int optind;
    int c;
    uint8_t adapter = 1;
    uint8_t addr = 0x27;
    uint8_t columns = 20; 
    uint8_t rows = 4;

    while ((c = getopt(argc, argv, "d:c:r:a:")) != -1) {
        switch (c) {
        case 'd':
            adapter = (uint8_t) atoi(optarg);
            break;
        case 'a':
            addr = (uint8_t) strtol(optarg, NULL, 16);
            break;
        case 'c':
            columns = (uint8_t) atoi(optarg);
            break;
        case 'r':
            rows = (uint8_t) atoi(optarg);
            break;
	default :
            usage(argv[0]);
        }
    }

#if !defined(ARDUINO)
    fprintf(stderr, "addr %d columns %d rows %d adapter %d\n", 
        addr, columns, rows, adapter);
#endif
    LiquidCrystal_I2C lcd(addr, columns, rows, adapter);  

    setup(lcd);

    while (1) {
        loop();
    }
}

#endif
