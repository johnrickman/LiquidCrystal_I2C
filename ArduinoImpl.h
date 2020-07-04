#ifndef _ARDUINOIMPL_H_
#define _ARDUINOIMPL_H_

#include "LCI2CImpl.h"
#include "LiquidCrystal_I2C.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#define printIIC(args)  Wire.write(args)
#else
#include "WProgram.h"
#define printIIC(args)  Wire.send(args)
#endif

#include "Wire.h"

class ArduinoImpl : public LCI2CImpl { 
public:
    ArduinoImpl(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
    virtual ~ArduinoImpl() {};
    virtual void init_priv();
    virtual void setBacklightVal(uint8_t val);
    virtual void delayMilliseconds(uint32_t val);
    virtual void delayMicroseconds(uint32_t val);
    virtual void expanderWrite(uint8_t _data);
private:
    uint8_t _Addr;
    uint8_t _cols;
    uint8_t _rows;
    uint8_t _backlightval;
};

#endif
