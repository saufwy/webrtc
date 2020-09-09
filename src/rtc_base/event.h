#ifndef _RTC_BASE_EVENT_H_
#define _RTC_BASE_EVENT_H_

#include <pthread.h>
#include "rtc_base/constructormagic.h"

namespace rtc {

class Event {
public:
    static const int kForever = -1;
    Event(bool manual_reset, bool initially_signaled);
    ~Event();

    void Set();
    void Reset();
    bool Wait(int milliseconds);

private:
    pthread_mutex_t event_mutex_;
    pthread_cond_t event_cond_;
    const bool is_manual_reset_;
    bool event_status_;

    RTC_DISALLOW_IMPLICIT_CONSTRUCTORS(Event);
};

} // namespace rtc

#endif

