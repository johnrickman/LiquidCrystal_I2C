#ifndef _LCI2CIMPL_H_
#define _LCI2CIMPL_H_

#include <inttypes.h>

class LCI2CImpl { 
public:
    LCI2CImpl();
    virtual void delayMilliseconds(uint32_t delay) = 0;
    virtual void delayMicroseconds(uint32_t delay) = 0;
};

#endif
