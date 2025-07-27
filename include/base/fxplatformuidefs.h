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
    #if defined MULTITOUCH
        #define HAS_MULTITOUCH
        //#define HAS_SCREEN_KBD
    #endif
    #ifdef DDRAW
        #define BACKEND_DIRECTDRAW
    #endif
#elif defined (PLATFORM_MACOSX)
    #define BACKEND_COCOA 1
#elif defined (PLATFORM_IOS)
    #define BACKEND_UIKIT 1
    #define HAS_MULTITOUCH
    #define HAS_SCREEN_ROTATE
    #define HAS_SCREEN_KBD
    #if GLES
        #define BACKEND_GL_ES
    #endif
#elif defined (PLATFORM_LINUX)
/*#elif defined (PLATFORM_UNIX_COMPATIBLE) \
&& (!defined(PLATFORM_ANDROID) || !defined(PLATFORM_HAIKU) \
|| !defined(PLATFORM_BEOS) || !defined(PLATFORM_MACOSX) || \
!defined(PLATFORM_QNX) || !defined(PLATFORM_FUCHSIA) || \
!defined(PLATFORM_PLAN9))*/
    #define BACKEND_X11 1
    #if defined MULTITOUCH
        #define HAS_MULTITOUCH
    #endif
        #ifdef BACKEND_WITH_GL
            #ifdef GLX
                #define BACKEND_GLX
            #elif EGL
                #define BACKEND_EGL
            #elif GLES
                #define BACKEND_GL_ES
            #endif
        #endif
    #ifdef VULKAN
        #define HAS_VULKAN
    #endif
#elif defined (PLATFORM_ANDROID)
    #define BACKEND_ANDROID 1
    #define HAS_MULTITOUCH
    #define HAS_SCREEN_ROTATE
    #define HAS_SCREEN_KBD
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
