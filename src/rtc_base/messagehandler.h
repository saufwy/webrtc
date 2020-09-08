#ifndef _RTC_BASE_MESSAGEHANDLER_H_
#define _RTC_BASE_MESSAGEHANDLER_H_

#include <memory>
#include <utility>

#include "rtc_base/constructormagic.h"

namespace rtc {

struct Message;

class MessageHandler {
public:
    virtual ~MessageHandler();
    virtual void OnMessage(Message* msg) = 0;

protected:
    MessageHandler() {}

private:
    RTC_DISALLOW_COPY_AND_ASSIGN(MessageHandler);
};

template<class ReturnT, class FunctorT>
class FunctorMessageHandler {
public:
    explicit FunctorMessageHandler(FunctorT&& functor)
        : functor_(std::forward<FunctorT>(functor)) {}
    virtual void OnMessage(Message* msg) {
        result_ = functor_();
    }

    const ReturnT& result() const {
        return result_;
    }

    ReturnT MoveResult() {
        return std::move(result_);
    }

private:
    FunctorT functor_;
    ReturnT result_;
};
} // namespace rtc

#endif

