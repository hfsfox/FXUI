#include "MacOSXAPIWindow.h"

#if defined (BACKEND_COCOA)

#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>

#define cls objc_getClass
#define sel sel_getUid
#define msg ((id(*)(id, SEL, ...))objc_msgSend)
#define cls_msg ((id(*)(Class, SEL, ...))objc_msgSend)

@interface CocoaAPIWindow : NSWindow
{
}
@end

@implementation CocoaAPIWindow

@end

@interface CocoaAPIView : NSView
//- (BOOL)	acceptsFirstResponder;
//- (BOOL)	isOpaque;

@end

@implementation CocoaAPIView

@end

@interface CocoaAPIMenuBar: NSMenu
@end

@implementation CocoaAPIMenuBar: NSMenu
@end

MacOSXAPIWindow::MacOSXAPIWindow(FX::FXRect frame, const char* title)
{
};

bool
MacOSXAPIWindow::QuitRequested()
{
};



#endif



