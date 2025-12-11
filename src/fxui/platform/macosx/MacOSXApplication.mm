#include "MacOSXApplication.h"
#include <AppKit/AppKit.h>
#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Foundation/NSString.h>

namespace
{
    NSAutoreleasePool* _pool;
}

MacOSXApplication::MacOSXApplication()
{
    _pool = [[NSAutoreleasePool alloc]init];
    NSApp = [NSApplication sharedApplication];
    // This causes the main window and menubar to raise
    [NSApp activateIgnoringOtherApps: YES];

    this->Run();
}

MacOSXApplication::~MacOSXApplication()
{
	[NSApp release];
	[_pool release];
}

void
MacOSXApplication::Shutdown()
{
    [NSApp stop: nil];

    // force an event into the event queue. Otherwise, NSApp won't
    // fall out of its loop. Alternative is for the user to wiggle
    // the mouse. Clearly, this is a bug in NSApplication of some kind.
    // see http://ftp2.tw.freebsd.org/pub/FreeBSD/distfiles/cs-pseudo-stable-2005-09-03.tar.bz2/CS/libs/csutil/macosx/ for acknowledgments.

    /*
    [NSApp postEvent: [NSEvent otherEventWithType:NSApplicationDefined
        location:NSMakePoint(0,0)
        modifierFlags:0
        timestamp:0
        windowNumber:0
        context:[NSApp context] subtype:0x3d8a data1:0x1827 data2:0x4851]
        atStart:NO];
        */
}

void
MacOSXApplication::Run()
{
   // in cocoa, we invoke the main loop this way

    [NSApp run];

    // when we get here, application has left its main loop
}
