#include "MacOSXAPIWindow.h"

#if defined (BACKEND_COCOA)

@interface CocoaAPIWindow : NSWindow
{
}
@end

@implementation CocoaAPIXWindow

@end

@interface CocoaAPIView : NSView
//- (BOOL)	acceptsFirstResponder;
//- (BOOL)	isOpaque;

@end

@implementation CocoaAPIView

@end

MacOSXWindow::MacOSXWindow(FX::FXRect frame, const char* title)
{
};

bool
MacOSXAPIWindow::QuitRequested()
{
};



#endif



