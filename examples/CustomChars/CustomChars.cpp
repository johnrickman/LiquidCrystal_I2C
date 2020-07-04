//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include "LiquidCrystal_I2C.h"

#if !defined(ARDUINO) || (defined(ARDUINO) && ARDUINO >= 100)
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t note[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrow[8] = {	0x1,0x1,0x5,0x9,0x1f,0x8,0x4};

#if !defined(ARDUINO)
#include <stdio.h>
#endif
  
// display all keycodes
void displayKeyCodes(LiquidCrystal_I2C &lcd) {
#if !defined(ARDUINO)
  fprintf(stderr, "%s enter\n", __FUNCTION__);
#endif
  uint8_t i = 0;
  while (1) {
    lcd.clear();
    lcd.print("Codes 0x"); lcd.print(i, HEX);
    lcd.print("-0x"); lcd.print(i+15, HEX);
    lcd.setCursor(0, 1);
    for (int j=0; j<16; j++) {
      lcd.printByte(i+j);
    }
    i+=16;
    
    lcd.delay(4000);
  }
}

void setupInternal(LiquidCrystal_I2C &lcd)
{
#if !defined(ARDUINO)
  fprintf(stderr, "%s enter\n", __FUNCTION__);
#endif
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, clock);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);
  lcd.home();
  
  lcd.print("Hello world...");
  lcd.setCursor(0, 1);
  lcd.print(" i ");
  lcd.printByte(3);
#if defined(ARDUINO)
  lcd.print(" arduinos!");
#else
  lcd.print(" raspberry pis!");
#endif
  lcd.delay(5000);
  displayKeyCodes(lcd);
}

void setup()
{
#if !defined(ARDUINO)
  fprintf(stderr, "%s enter\n", __FUNCTION__);
#endif
    LiquidCrystal_I2C lcd(0x27, 20, 4);  
    setupInternal(lcd);
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

    setupInternal(lcd);

    while (1) {
        loop();
    }
}

#endif
