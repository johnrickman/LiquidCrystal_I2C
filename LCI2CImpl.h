#ifndef _LCI2CIMPL_H_
#define _LCI2CIMPL_H_

#include <inttypes.h>

class LCI2CImpl {
public:
    LCI2CImpl();
    virtual void delayMilliseconds(uint32_t delay) = 0;
    virtual void delayMicroseconds(uint32_t delay) = 0;
    virtual void createChar(uint8_t location, uint8_t charmap[]) = 0;
    virtual void createChar(uint8_t location, const char *charmap) = 0;
    virtual void printstr(const char c[]) = 0;
};

#endif
