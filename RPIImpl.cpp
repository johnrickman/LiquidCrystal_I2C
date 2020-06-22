#include "RPIImpl.h"
#include <inttypes.h>

#include <time.h>
#include <errno.h>  
#include <cstdio>

RPIImpl::RPIImpl()
{
}

void RPIImpl::delayMilliseconds(uint32_t delay)
{
    // XXX this may need to push down to driver, given in userland, hard
    // to make strong promises about delays.

    struct timespec ts;
    int res;

    ts.tv_sec = delay / 1000;
    ts.tv_nsec = (delay % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}

void RPIImpl::delayMicroseconds(uint32_t delay)
{
    // XXX this may need to push down to driver, given in userland, hard
    // to make strong promises about delays.

    struct timespec ts;
    int res;

    ts.tv_sec = delay / 1000000;
    ts.tv_nsec = (delay % 1000000) * 1000000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);
}

void RPIImpl::createChar(uint8_t location, uint8_t charmap[])
{
#if defined(NOT_YET)
    location &= 0x7; // we only have 8 locations 0-7
    command(LCD_SETCGRAMADDR | (location << 3));
    for (int i=0; i<8; i++) {
        write(charmap[i]);
    }
#endif
}

void RPIImpl::createChar(uint8_t location, const char *charmap)
{
#if defined(NOT_YET)
    location &= 0x7; // we only have 8 locations 0-7
    command(LCD_SETCGRAMADDR | (location << 3));
    for (int i=0; i<8; i++) {
        write(pgm_read_byte_near(charmap++));
    }
#endif
}

void RPIImpl::printstr(const char c[])
{
    printf("%s\n", c);
}

