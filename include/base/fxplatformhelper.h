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
#elif defined (PLATFORM_WINDOWS)
#endif

#if !defined (PLATFORM_HAIKU)
typedef uint32_t status_t;
#endif