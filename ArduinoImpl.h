#ifndef _ARDUINOIMPL_H_
#define _ARDUINOIMPL_H_

#include "LCI2CImpl.h"
#include "LiquidCrystal_I2C.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"
#include "Print.h"

class ArduinoImpl : public LCI2CImpl { 
public:
    ArduinoImpl();
    virtual ~ArduinoImpl() {};
    virtual void delayMilliseconds(uint32_t val);
    virtual void delayMicroseconds(uint32_t val);
    virtual void createChar(uint8_t location, uint8_t charmap[]);
    virtual void createChar(uint8_t location, const char *charmap);
    virtual void printstr(const char c[]);
#if defined(ARDUINO) && ARDUINO >= 100
#define printIIC(args)  Wire.write(args)
#if 0
inline size_t ArduinoImpl::write(uint8_t value) {
        send(value, Rs);
        return 1;
}
#endif
#else
#define printIIC(args)  Wire.send(args)
#if 0
inline void ArduinoImpl::write(uint8_t value) {
        send(value, Rs);
}
#endif
#endif
    virtual size_t print(const char arg1[]);
    virtual size_t print(char arg1);
    virtual size_t print(unsigned char arg1, int arg2);
    virtual size_t print(int arg1, int arg2);
    virtual size_t print(unsigned int arg1);
    virtual size_t print(long arg1, int arg2);
    virtual size_t print(unsigned int arg1, int arg2);
    virtual size_t print(unsigned long arg1, int arg2);
    virtual size_t print(double arg1, int arg2 = 2);
};

#endif
