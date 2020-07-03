#ifndef _LCI2CIMPL_H_
#define _LCI2CIMPL_H_

#include <inttypes.h>
#include <stddef.h> 

class LCI2CImpl {
public:
    virtual ~LCI2CImpl() {};
    virtual void init_priv() = 0;
    virtual void setBacklightVal(uint8_t backlightval) = 0;
    virtual void expanderWrite(uint8_t _data) = 0;
    virtual void delayMilliseconds(uint32_t delay) = 0;
    virtual void delayMicroseconds(uint32_t delay) = 0;
};

#endif
