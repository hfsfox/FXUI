//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT Licesnse
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#include <fxplatformdefs.h>

#if defined (PLATFORM_MACOSX)
	#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4
		typedef int NSInteger;
		typedef unsigned int NSUInteger;
	#endif
	#if MAC_OS_X_VERSION_10_12
		#define NSControlKeyMask NSEventModifierFlagControl
		#define NSAlternateKeyMask NSEventModifierFlagOption
		#define NSShiftKeyMask NSEventModifierFlagShift
		#define NSCommandKeyMask NSEventModifierFlagCommand
		//
		#define NSLeftMouseDown NSEventTypeLeftMouseDown
		#define NSRightMouseDown NSEventTypeRightMouseDown
		#define NSOtherMouseDown NSEventTypeOtherMouseDown
		#define NSLeftMouseUp NSEventTypeLeftMouseUp
		#define NSRightMouseUp NSEventTypeRightMouseUp
		#define NSOtherMouseUp NSEventTypeOtherMouseUp
		#define NSLeftMouseDragged NSEventTypeLeftMouseDragged
		#define NSRightMouseDragged NSEventTypeRightMouseDragged
		#define NSOtherMouseDragged NSEventTypeOtherMouseDragged
		#define NSKeyDown NSEventTypeKeyDown
		#define NSKeyUp NSEventTypeKeyUp
		#define NSFlagsChanged NSEventTypeFlagsChanged
		#define NSApplicationDefined NSEventTypeApplicationDefined
		#define NSPeriodic NSEventTypePeriodic
		#define NSMouseMoved NSEventTypeMouseMoved
		//
		#define NSRegularControlSize NSControlSizeRegular
		#define NSSmallControlSize NSControlSizeSmall
		//
		#define NSAnyEventMask NSEventMaskAny
		#define NSLeftMouseDraggedMask NSEventMaskLeftMouseDragged
		#define NSLeftMouseUpMask NSEventMaskLeftMouseUp
		//
		#define NSTickMarkAbove NSTickMarkPositionAbove
		//
		#define NSBorderlessWindowMask NSWindowStyleMaskBorderless
		#define NSTitledWindowMask NSWindowStyleMaskTitled
		#define NSClosableWindowMask NSWindowStyleMaskClosable
		#define NSMiniaturizableWindowMask NSWindowStyleMaskMiniaturizable
		#define NSResizableWindowMask NSWindowStyleMaskResizable
	#endif
#elif defined (PLATFORM_WINDOWS)
#endif

#if !defined (PLATFORM_HAIKU)
typedef uint32_t status_t;
#endif
