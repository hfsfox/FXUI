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

#ifndef     __FXTIMEUTILS__
#define     __FXTIMEUTILS__

#include <fxplatformdefs.h>
#include <inttypes.h>
//#include <unistd.h>
#include <time.h>

typedef struct _NanosecondsTime
{
	int64_t sec;
	int32_t nsec;
} NanosecondsTime;

namespace FX
{
    /*
    NanosecondsTime GetNanosecondsTime(void)
    {

    }*/
    inline int32_t GetTickCount()
    {
        //#ifdef __APPLE__
        #if defined PLATFORM_MACOSX
        // could switch to mach_getabsolutetime() maybe
        struct timeval tm={0,};
        gettimeofday(&tm,NULL);
        return (int32_t) (tm.tv_sec*1000 + tm.tv_usec/1000);
        #elif defined PLATFORM_WINDOWS
        return (int32_t)(GetTickCount64());
        #elif defined PLATFORM_LINUX
        //
        struct timespec ts={0,};
        clock_gettime(CLOCK_REALTIME, &ts);
        return (int32_t) (ts.tv_sec*1000 + ts.tv_nsec/1000000);
        #else
        struct timespec ts={0,};
        clock_gettime(CLOCK_MONOTONIC,&ts);
        return (int32_t) (ts.tv_sec*1000 + ts.tv_nsec/1000000);
        #endif
    }
}

#endif
