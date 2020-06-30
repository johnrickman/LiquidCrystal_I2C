#ifndef _LCI2CIMPL_H_
#define _LCI2CIMPL_H_

#include <inttypes.h>
#include <stddef.h> 

class LCI2CImpl {
public:
    LCI2CImpl();
    virtual ~LCI2CImpl() {};
    virtual void delayMilliseconds(uint32_t delay) = 0;
    virtual void delayMicroseconds(uint32_t delay) = 0;
    virtual void createChar(uint8_t location, uint8_t charmap[]) = 0;
    virtual void createChar(uint8_t location, const char *charmap) = 0;
    virtual void printstr(const char c[]) = 0;
    virtual size_t print(const char arg1[]) = 0;
    virtual size_t print(char arg1) = 0;
    virtual size_t print(unsigned char arg1, int arg2) = 0;
    virtual size_t print(int arg1, int arg2) = 0;
    virtual size_t print(unsigned int arg1, int arg2) = 0;
    virtual size_t print(long arg1, int arg2) = 0;
    virtual size_t print(unsigned long arg1, int arg2) = 0;
    virtual size_t print(double arg1, int arg2 = 2) = 0;
};

#endif
