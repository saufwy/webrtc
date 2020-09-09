#include "rtc_base/event.h"
#include "rtc_base/checks.h"

namespace rtc {

Event::Event(bool manual_reset, bool initially_signaled)
    : is_manual_reset_(manual_reset), event_status_(initially_signaled) {
    RTC_CHECK(pthread_mutex_init(&event_mutex_, nullptr) == 0);
    pthread_condattr_t cond_attr;
    RTC_CHECK(pthread_condattr_init(&cond_attr) == 0);
    RTC_CHECK(pthread_cond_init(&event_cond_, &cond_attr));
    pthread_condattr_destroy(&cond_attr);
}

Event::~Event() {
    pthread_mutex_destroy(&event_mutex_);
    pthread_cond_destroy(&event_cond_);
}


void Event::Reset() {
    pthread_mutex_lock(&event_mutex_);
    event_status_ = false;
    pthread_mutex_unlock(&event_mutex_);
}

void Event::Set() {
    pthread_mutex_lock(&event_mutex_);
    event_status_ = true;
    pthread_mutex_unlock(&event_mutex_);
    pthread_cond_broadcast(&event_cond_);
}

bool Event::Wait(int milliseconds) {
    (void)milliseconds;
    int error = 0;
    pthread_mutex_lock(&event_mutex_);
    while (!event_status_ && error == 0) {
        error = pthread_cond_wait(&event_cond_, &event_mutex_);
    }
    if (error == 0 && !is_manual_reset_) {
        event_status_ = false;
    }
    pthread_mutex_unlock(&event_mutex_);
    return (error == 0);
}

} // namespace rtc

