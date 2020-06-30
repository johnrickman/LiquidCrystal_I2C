#ifndef _RPIIMPL_H_
#define _RPIIMPL_H_

#if !defined(ARDUINO)
#include "LCI2CImpl.h"

class RPIImpl : public LCI2CImpl { 
public:
    RPIImpl();
    virtual ~RPIImpl() {};
    virtual void delayMilliseconds(uint32_t delay);
    virtual void delayMicroseconds(uint32_t delay);
    virtual void createChar(uint8_t location, uint8_t charmap[]);
    virtual void createChar(uint8_t location, const char *charmap);
    virtual void printstr(const char c[]);

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

#endif // !ARDUINO

#endif
