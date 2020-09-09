#ifndef _RTC_BASE_SOCKETSERVER_H_
#define _RTC_BASE_SOCKETSERVER_H_

#include <memory>
#include "rtc_base/socketfactory.h"

namespace rtc {

class SocketServer : public SocketFactory {
public:
    static const int kForever = -1;

    static std::unique_ptr<SocketServer> CreateDefault();

    virtual bool Wait(int cms, bool process_io) = 0;
    virtual void WakeUp() = 0;
};

} // namespace rtc

#endif

