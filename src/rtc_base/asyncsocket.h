#ifndef _RTC_BASE_ASYNSSOCKET_H_
#define _RTC_BASE_ASYNCSOCKET_H_

#include "rtc_base/socket.h"

namespace rtc {

class AsyncSocket : public Socket {
public:
    AsyncSocket();
    virtual ~AsyncSocket() override;
};

} // namespace rtc

#endif

