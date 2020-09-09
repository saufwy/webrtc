#ifndef _RTC_BASE_SOCKET_H_
#define _RTC_BASE_SOCKET_H_

#include <errno.h>

#include "rtc_base/socketaddress.h"

namespace rtc {

class Socket {
public:
    virtual ~Socket() {}

    virtual SocketAddress GetLocalAddress() const = 0;
    virtual SocketAddress GetRemoteAddress() const = 0;

};
} // namespace rtc

#endif

