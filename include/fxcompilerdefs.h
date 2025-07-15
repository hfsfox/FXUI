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

#ifndef __FXCOMPILERDEFS_H__
#define __FXCOMPILERDEFS_H__
#endif

// Detect compiler
#if defined(__clang__) || defined (__llvm__)
    #define COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
    #define COMPILER_GCC
#elif defined(__INTEL_COMPILER) || defined (__ICC)
    #define COMPILER_ICC
#elif defined(_MSC_VER)
    #define COMPILER_MSVC
#elif defined(__WATCOMC__)
    #define COMPILER_WATCOM
#elif defined(__xlc) || defined(__xlC) || defined(__xlC__) || defined(__IBMC__) || defined(__IBMCPP__)
    #define COMPILER_XLC
#elif defined(__MWERKS__) || defined(__CWCC__)
    #define COMPILER_MWERKS
#elif defined(__sgi) || defined(sgi) && defined(_SGI_COMPILER_VERSION)
    #define COMPILER_MIPSPRO
#elif defined(__HP_aCC)
    #define COMPILER_HP_ACC
#elif defined(__SUNPRO_CC) || defined(__SUNPRO_C)
    #define COMPILER_SUNPRO
#elif defined(__ghs) || defined(__ghs__)
    #define COMPILER_GREENHILLS
#elif defined(__EDG__) || defined (__EDG_VERSION__)
    #define COMPILER_EDG_COMPATIBLE
#elif defined(__LCC__) && !defined(__MCST__)
    #define COMPILER_LCC
#elif defined(__MCST__)
    #define COMPILER_MCST_LCC
#elif defined(__TINYC__)
    #define COMPILER_TCC
#elif defined(__VBCC__)
    #define COMPILER_VBCC
#elif defined (SDCC) || defined (__SDCC)
    #define COMPILER_SDCC
#elif defined(__IAR_SYSTEMS_ICC__) || defined(__ICCARM__)
    #define COMPILER_IAR
#elif defined (__CC_ARM)
    #define COMPILER_ARMCC
    #if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
        #define COMPILER_CLANG
    #endif
#elif defined (__TI_ARM__)
    #define COMPILER_TI
#elif defined (__CSMC__)
    #define COMPILER_COSMIC
#else
#warning "Unsupported compiler!"
#endif
