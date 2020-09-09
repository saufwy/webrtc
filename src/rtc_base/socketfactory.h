#ifndef _SOCKETFACTORY_H_
#define _SOCKETFACTORY_H_

#include "rtc_base/socket.h"
#include "rtc_base/asyncsocket.h"

namespace rtc {

class SocketFactory {
public:
    virtual ~SocketFactory() {}

    virtual Socket* CreateSocket(int family, int type) = 0;
    virtual AsyncSocket* CreateAsyncSocket(int family, int type) = 0;
};

} // namespace rtc

#endif

