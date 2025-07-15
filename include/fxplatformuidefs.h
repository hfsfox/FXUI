//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#include "fxplatformdefs.h"

#ifndef __FXPLATFORMUIDEFS_H__
#define __FXPLATFORMUIDEFS_H__
#endif

#if defined (PLATFORM_WINDOWS)
#define BACKEND_WINAPI 1
#elif defined (PLATFORM_MACOSX)
#define BACKEND_COCOA 1
#elif defined (PLATFORM_LINUX)
/*#elif defined (PLATFORM_UNIX_COMPATIBLE) \
&& (!defined(PLATFORM_ANDROID) || !defined(PLATFORM_HAIKU) \
|| !defined(PLATFORM_BEOS) || !defined(PLATFORM_MACOSX) || \
!defined(PLATFORM_QNX) || !defined(PLATFORM_FUCHSIA) || \
!defined(PLATFORM_PLAN9))*/
#define BACKEND_X11 1
#elif defined (PLATFORM_ANDROID)
#define BACKEND_ANDROID 1
#elif defined (PLATFORM_FUCHSIA)
#define BACKEND_SCENIC 1
#elif defined (PLATFORM_QNX)
#define BACKEND_PHOTON 1
#elif defined (PLATFORM_HAIKU) || defined(PLATFORM_BEOS)
#define BACKEND_BEAPI 1
#elif defined (PLATFORM_AMIGA_COMPATIBLE)
#define BACKEND_MUI 1
#elif defined (PLATFORM_RISCOS)
#define BACKEND_RISCOS 1
#endif

/*
|| !defined(PLATFORM_) || !defined(PLATFORM_) \\
|| !defined(PLATFORM_) || || !defined(PLATFORM_) \\
|| !defined(PLATFORM_) || !defined(PLATFORM_)
*/
