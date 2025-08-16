#ifdef BACKEND_COCOA

#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>

//NSApplication       *NSApplicationInstance;

class MacOSXWindow: public NSWindow
{
    public:
        MacOSXWindow(BRect frame, const char* title);
        virtual bool QuitRequested() override;
        bool ShouldClose() const { return fShouldClose; }
        volatile bool fShouldClose;
};

#endif
