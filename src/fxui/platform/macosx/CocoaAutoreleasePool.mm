#if defined (BACKEND_COCOA)
#include "CocoaAutoreleasePool.h"
#include <AppKit/AppKit.h>
#include <Cocoa/Cocoa.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <objc/objc-runtime.h>

extern "C"
{
    void* objc_autoreleasePoolPush(void);
    void objc_autoreleasePoolPop(void* pool);
}

FXCocoaAutoreleasePool::FXCocoaAutoreleasePool()
{
    autorelease_pool = objc_autoreleasePoolPush();
};

FXCocoaAutoreleasePool::~FXCocoaAutoreleasePool()
{
    objc_autoreleasePoolPop(autorelease_pool);
};

#endif
