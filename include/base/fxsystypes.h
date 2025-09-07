#ifndef __FXSYSTYPES_H__
#define __FXSYSTYPES_H__
#endif
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

#include <sys/types.h>
#include <stddef.h>

#if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64) || defined(_M_AMD64)
    #define ARCH_X86_64
#elif defined(__i386__) || defined(__i386)
    #define ARCH_X86
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define ARCH_ARM64
#elif defined(__arm__) || defined(__arm) || defined(_M_ARM) || defined(_ARM) || defined(__ARM_ARCH)
    #define ARCH_ARM
#elif defined(__PPC64__) || defined(__ppc64__) || defined(__ppc64) || defined(__powerpc64__) || defined(_ARCH_PPC64)
    #define ARCH_PPC64
#elif defined(__PPC__) || defined(__ppc__) || defined(__powerpc__) || defined(__ppc) || defined(_M_PPC) || defined(_ARCH_PPC)
    #define ARCH_PPC
#elif defined(__mips__) || defined(__mips) || defined(__MIPS__)
    #define ARCH_MIPS
#elif defined(__sparc__) || defined(__sparc)
    #define ARCH_SPARC
#elif defined(__riscv) && (__riscv_xlen == 64)
    #define ARCH_RISCV
    #define ARCH_RISCV64
#elif defined(__riscv) && (__riscv_xlen == 32)
    #define ARCH_RISCV
    #define ARCH_RISCV32
#elif defined(__loongarch64)
    #define ARCH_LOONGARCH
    #define ARCH_LOONGARCH64
#elif defined(__loongarch32)
    #define ARCH_LOONGARCH
    #define ARCH_LOONGARCH32
#elif defined(__e2k__)
    #define ARCH_E2K
#elif defined(__hppa__)
    #define ARCH_HP_PARISC
#elif defined(__ia64__)
    #define ARCH_ITANIUM
#elif defined(__OR1K__) || defined(__or1k__)
    #define ARCH_OPENRISC
#elif defined(__m68k__)
    #define ARCH_M68K
#elif defined(__AVR__) || defined(__AVR_ARCH__)
    #define ARCH_AVR
#else
    #if !defined (_WIN32)
        #warning "Unsupported architecture!"
    #else
        #pragma message("Unsupported architecture!")
    #endif
#endif

#ifndef _WIN32
#if defined(__WORDSIZE) && (__WORDSIZE == 128)
    #define ARCH_128BIT
#elif defined(__SIZE_WIDTH__) && (__SIZE_WIDTH__ == 128)
    #define ARCH_128BIT
#elif defined(__WORDSIZE) && (__WORDSIZE == 64)
    #define ARCH_64BIT
#elif defined(__SIZE_WIDTH__) && (__SIZE_WIDTH__ == 64)
    #define ARCH_64BIT
#elif defined(__WORDSIZE) && (__WORDSIZE == 32)
    #define ARCH_32BIT
#elif defined(__SIZE_WIDTH__) && (__SIZE_WIDTH__ == 32)
    #define ARCH_32BIT
#else
    #if !defined (_WIN32)
        #warning "Unsupported architecture!"
    #else
        #pragma message("Unsupported architecture!")
    #endif
#endif /* __WORDSIZE, __SIZE_WIDTH__ */
#endif
