#include "RPIImpl.h"
#include <inttypes.h>

#include <time.h>
#include <errno.h>  

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

