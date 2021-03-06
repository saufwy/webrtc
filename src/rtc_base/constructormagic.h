#ifndef _RTC_BASE_CONSTRUCTORMAGIC_H_
#define _RTC_BASE_CONSTRUCTORMAGIC_H_  

#define RTC_DISALLOW_ASSIGN(TypeName) \
    void operator=(const TypeName&) = delete

#define RTC_DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&) = delete;        \
    RTC_DISALLOW_ASSIGN(TypeName)

#define RTC_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
    TypeName() = delete;                             \
    RTC_DISALLOW_COPY_AND_ASSIGN(TypeName)

#endif

