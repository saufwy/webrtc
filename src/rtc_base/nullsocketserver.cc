#include "rtc_base/nullsocketserver.h"

namespace rtc {

NullSocketServer::NullSocketServer() : event_(false, false) {}

NullSocketServer::~NullSocketServer() {}

bool NullSocketServer::Wait(int cms, bool) {
    event_.Wait(cms);
    return true;
}

void NullSocketServer::WakeUp() {
    event_.Set();
}

Socket* NullSocketServer::CreateSocket(int, int) {
    return nullptr;
}

AsyncSocket* NullSocketServer::CreateAsyncSocket(int, int) {
    return nullptr;
}

} // namespace rtc

