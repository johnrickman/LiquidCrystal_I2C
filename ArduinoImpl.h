#ifndef _ARDUINOIMPL_H_
#define _ARDUINOIMPL_H_

#include "LCI2CImpl.h"

class class ArduinoImpl : public LCI2CImpl { 
public:
    ArduinoImpl();
    virtual ~ArduinoImpl() {};
    virtual void delayMilliseconds(uint32_t delay);
    virtual void delayMicroseconds(uint32_t delay);
};

#endif
