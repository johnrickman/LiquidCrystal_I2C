#include "ArduinoImpl.h"
#include <inttypes.h>

ArduinoImpl::ArduinoImpl(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows)
{
    _Addr = lcd_Addr;
    _cols = lcd_cols;
    _rows = lcd_rows;
    _backlightval = LCD_NOBACKLIGHT;
}

void ArduinoImpl::setBacklightVal(uint8_t val)
{
    _backlightval = val;
}

void ArduinoImpl::delayMilliseconds(uint32_t val)
{
    ::delay(val);
}

void ArduinoImpl::delayMicroseconds(uint32_t val)
{
    ::delayMicroseconds(val);
}

void ArduinoImpl::init_priv()
{
    Serial.print("ArduinoImpl::init_priv\n");
    Wire.begin();
}

void ArduinoImpl::expanderWrite(uint8_t _data)
{                                        
    Wire.beginTransmission(_Addr);
    printIIC((int)(_data) | _backlightval);
    Wire.endTransmission();   
}
