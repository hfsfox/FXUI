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

#ifndef __FXPLATFORMEXPORT_H__
#define __FXPLATFORMEXPORT_H__

#include <fxplatformdefs.h>
#include <fxcompilerdefs.h>

#if defined FXUI_EXPORT
    #if defined PLATFORM_WINDOWS || defined __CYGWIN__
        #ifdef __GNUC__
            #define FXUI_EXPORT __attribute__((dllexport))
        #else
            #define EXUI_EXPORT __declspec(dllexport)
        #endif
    #else
        #if __GNUC__ >= 4 || defined(__clang__)
            #define FXUI_EXPORT __attribute__((visibility("default")))
        #else
            #define FXUI_EXPORT
        #endif
    #endif
#endif

#endif
