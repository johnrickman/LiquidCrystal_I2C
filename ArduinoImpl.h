#ifndef _ARDUINOIMPL_H_
#define _ARDUINOIMPL_H_

#include "LCI2CImpl.h"

class class ArduinoImpl : public LCI2CImpl { 
public:
    ArduinoImpl();
    virtual ~ArduinoImpl() {};
    virtual void delayMilliseconds(uint32_t delay);
    virtual void delayMicroseconds(uint32_t delay);
    virtual void createChar(uint8_t location, uint8_t charmap[]);
    virtual void createChar(uint8_t location, const char *charmap);
    virtual void printstr(const char c[]) = 0;
};

#endif
