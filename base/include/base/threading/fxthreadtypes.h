/**----------------------------------------------------------------------------
* FXUI SDK
* FXUI: Graphical User Interface Framework:
*
* Version 0.1       Date :
*
*------------------------------------------------------------------------------
* MIT
* © 2025, , All Rights Reserved
*------------------------------------------------------------------------------
**/

#ifndef __FXTHREADTYPES_H__
#define __FXTHREADTYPES_H__

#include <base/common/fxcompilerdefs.h>

#ifndef thread_local
    #if __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
        #define thread_local _Thread_local
    #elif defined PLATFORM_WINDOWS && ( \
        defined COMPILER_MSVC || \
        defined __ICL || \
        defined __DMC__ || \
        defined COMPILER_BORLAND )
        #define thread_local __declspec(thread)
        // note that ICC (linux) and Clang are covered by __GNUC__
    #elif defined COMPILER_GCC || defined COMPILER_SUNPRO || defined __hpux || \
        defined COMPILER_XLC
        #define thread_local __thread
    #else
            #error "Cannot define thread_local"
    #endif
#endif

enum thread_priority_t
{
    FX_NORMAL_PRIORITY,
    FX_HIGH_PRIORITY,
    FX_LOW_PRIORITY
};

#endif //__FXTHREADTYPES_H__
