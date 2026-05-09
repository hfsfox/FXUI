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

#ifndef __FXENDIAN_H__
#define __FXENDIAN_H__

#include <fxcompilerdefs.h>
#include <fxplatformdefs.h>

#if defied COMPILER_MSVC
    #include <stdlib.h>
#elif defined PLATFORM_APPLE
    #include <libkern/OSByteOrder.h>
#elif defined PLATFROM_SOLARIS
    #include <sys/byteorder.h>
#elif defined PLATFROM_FREEBSD
    #include <sys/endian.h>
#elif defined PLATFROM_OPENBSD
    #include <sys/types.h>
#elif defined PLATFROM_NETBSD
    #include <sys/types.h>
    #include <machine/bswap.h>
#elif defined PLATFORM_HAIKU || defined PLATFORM_BEOS
    #include <ByteOrder.h>
#else
    #include <byteswap.h>
#endif

/*
#ifdef _MSC_VER

#include <stdlib.h>
#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)

#elif defined(__APPLE__)

// Mac OS X / Darwin features
#include <libkern/OSByteOrder.h>
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)

#elif defined(__sun) || defined(sun)

#include <sys/byteorder.h>
#define bswap_32(x) BSWAP_32(x)
#define bswap_64(x) BSWAP_64(x)

#elif defined(__FreeBSD__)

#include <sys/endian.h>
#define bswap_32(x) bswap32(x)
#define bswap_64(x) bswap64(x)

#elif defined(__OpenBSD__)

#include <sys/types.h>
#define bswap_32(x) swap32(x)
#define bswap_64(x) swap64(x)

#elif defined(__NetBSD__)

#include <sys/types.h>
#include <machine/bswap.h>
#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
#define bswap_32(x) bswap32(x)
#define bswap_64(x) bswap64(x)
#endif

#else

#include <byteswap.h>

#endif
*/

namespace
{
    inline uint16_t byte_swap(uint16_t v)
    {
        return (v >> 8) | (v << 8);
    }

    inline uint32_t byte_swap(uint32_t v)
    {
        v   = ((v & 0xff00ff00) >> 8) | ((v & 0x00ff00ff) << 8);
        return (v >> 16) | (v << 16);
    }

    inline uint64_t byte_swap(uint64_t v)
    {
        v   = ((v & 0xff00ff00ff00ff00ULL) >> 8)  | ((v & 0x00ff00ff00ff00ffULL) << 8);
        v   = ((v & 0xffff0000ffff0000ULL) >> 16) | ((v & 0x0000ffff0000ffffULL) << 16);
        return (v >> 32) | (v << 32);
    }

    inline float byte_swap(float v)
    {
        union {
            float       fValue;
            uint32_t    uValue;
        } tmp;
        tmp.fValue      = v;
        tmp.uValue      = byte_swap(tmp.uValue);
        return tmp.fValue;
    }

    inline double byte_swap(double v)
    {
        union {
            double   fValue;
            uint64_t uValue;
        } tmp;
        tmp.fValue      = v;
        tmp.uValue      = byte_swap(tmp.uValue);
        return tmp.fValue;
    }

    inline void byte_swap(uint16_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(*v);
            v           ++;
        }
    }

    inline void byte_swap(int16_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(uint16_t(*v));
            v           ++;
        }
    }

    inline void byte_swap(uint32_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(*v);
            v           ++;
        }
    }

    inline void byte_swap(int32_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(uint32_t(*v));
            v           ++;
        }
    }

    inline void byte_swap(uint64_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(*v);
            v           ++;
        }
    }

    inline void byte_swap(int64_t *v, size_t n)
    {
        while (n--)
        {
            *v          = byte_swap(uint64_t(*v));
            v           ++;
        }
    }

    inline void byte_swap(float *v, size_t n)
    {
        union {
            float      *fValue;
            uint32_t   *uValue;
        } tmp;
        tmp.fValue      = v;
        uint32_t *p     = tmp.uValue;

        while (n--)
        {
            *p          = byte_swap(*p);
            p           ++;
        }
    }

    inline void byte_swap(double *v, size_t n)
    {
        union {
            double     *fValue;
            uint64_t   *uValue;
        } tmp;
        tmp.fValue      = v;
        uint64_t *p     = tmp.uValue;

        while (n--)
        {
            *p          = byte_swap(*p);
            p           ++;
        }
    }
}

namespace fx
{
    namespace endian
    {
        inline uint8_t byte_swap(uint8_t v)
        {
            return v;
        }
        inline int8_t byte_swap(int8_t v)
        {
            return v;
        }

        inline int16_t byte_swap(int16_t v)
        {
            return byte_swap(uint16_t(v));
        }

        inline int32_t byte_swap(int32_t v)
        {
            return byte_swap(uint32_t(v));
        }

        inline int64_t byte_swap(int64_t v)
        {
            return byte_swap(uint64_t(v));
        }
        //
    }
}

#endif
