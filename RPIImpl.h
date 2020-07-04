#ifndef _RPIIMPL_H_
#define _RPIIMPL_H_

#if !defined(ARDUINO)
#include "LCI2CImpl.h"

class RPIImpl : public LCI2CImpl { 
public:
    RPIImpl(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows);
    virtual ~RPIImpl() {};
    virtual void init_priv();
    virtual void setBacklightVal(uint8_t val);
    virtual void delayMilliseconds(uint32_t val);
    virtual void delayMicroseconds(uint32_t val);
    virtual void expanderWrite(uint8_t _data);
private:
    uint8_t _Addr;
    uint8_t _cols;
    uint8_t _rows;
    uint8_t _backlightval;
};

#endif // !ARDUINO

#endif
