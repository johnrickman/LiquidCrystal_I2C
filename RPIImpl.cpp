#if !defined(ARDUINO) 

#include "RPIImpl.h"
#include <inttypes.h>

#include <time.h>
#include <errno.h>  
#include <stdio.h>

RPIImpl::RPIImpl(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)
{
    _Addr = lcd_Addr;
    _cols = lcd_cols;
    _rows = lcd_rows;
    _backlightval = LCD_NOBACKLIGHT;
}

void RPIImpl::delayMilliseconds(uint32_t delay)
{
    // XXX this may need to push down to driver, given in userland, hard
    // to make strong promises about delays.

    struct timespec ts;
    int res;

    ts.tv_sec = delay / 1000;
    ts.tv_nsec = (delay % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}

void RPIImpl::delayMicroseconds(uint32_t delay)
{
    // XXX this may need to push down to driver, given in userland, hard
    // to make strong promises about delays.

    struct timespec ts;
    int res;

    ts.tv_sec = delay / 1000000;
    ts.tv_nsec = (delay % 1000000) * 1000000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}

void ArduinoImpl::setBacklightVal(uint8_t val)
{
    _backlightval = val;
}

void ArduinoImpl::init_priv()
{
#if defined(NOT_YET)
    Serial.print("ArduinoImpl::init_priv\n");
    Wire.begin();
#endif
}

void ArduinoImpl::expanderWrite(uint8_t _data)
{
#if defined(NOT_YET)
    Wire.beginTransmission(_Addr);
    printIIC((int)(_data) | _backlightval);
    Wire.endTransmission();
#endif
}

#endif // !ARDUINO
