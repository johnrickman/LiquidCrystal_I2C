#ifndef _RPIIMPL_H_
#define _RPIIMPL_H_

#include "LCI2CImpl.h"

class RPIImpl : public LCI2CImpl { 
public:
    RPIImpl();
    virtual ~RPIImpl() {};
    virtual void delayMilliseconds(uint32_t delay);
    virtual void delayMicroseconds(uint32_t delay);
    virtual void createChar(uint8_t location, uint8_t charmap[]);
    virtual void createChar(uint8_t location, const char *charmap);
    virtual void printstr(const char c[]) = 0;
};

#endif
