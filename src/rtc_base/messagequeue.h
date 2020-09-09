#ifndef _RTC_BASE_MESSAGEQUEUE_H_
#define _RTC_BASE_MESSAGEQUEUE_H_

#include <stdint.h>
#include <list>

#include "rtc_base/messagehandler.h"


namespace rtc {

class MessageData {
public:
    MessageData() {}
    virtual ~MessageData() {}
};

struct Message {
    Message()
        : phandler(nullptr), message_id(0), pdata(nullptr), ts_sensitive(0)

    Location posted_from;
    MessageHandler* phandler;
    uint32_t message_id;
    MessageData* pdata;
    int64_t ts_sensitive;
};

typedef std::list<Message> MessageList;

} // namespace rtc

#endif

