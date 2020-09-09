#ifndef _RTC_BASE_NULLSOCKETSERVER_H_
#define _RTC_BASE_NULLSOCKETSERVER_H_

#include "rtc_base/event.h"
#include "rtc_base/socketserver.h"

namespace rtc {

class NullSocketServer : public SocketServer {
public:
    NullSocketServer();
    virtual ~NullSocketServer() override;

    virtual bool Wait(int cms, bool process_io) override;
    virtual void WakeUp() override;

    Socket* CreateSocket(int family, int type) override;
    AsyncSocket* CreateAsyncSocket(int family, int type) override;

private:
    Event event_;

};

} // namespace rtc

#endif

