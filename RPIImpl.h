#ifndef _RPIIMPL_H_
#define _RPIIMPL_H_

#include "LCI2CImpl.h"

class RPIImpl : public LCI2CImpl { 
public:
    RPIImpl();
    virtual ~RPIImpl() {};
    virtual void delayMilliseconds(uint32_t delay);
    virtual void delayMicroseconds(uint32_t delay);
};

#endif
