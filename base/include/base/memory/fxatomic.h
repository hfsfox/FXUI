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

#ifndef     __FXATOMIC_H__
#define     __FXATOMIC_H__

#include <base/common/fxcompilerdefs.h>

#if defined(COMPILER_MSVC)
    #include <intrin.h>
#endif

typedef enum {
    ATOMIC_RELAXED,
    ATOMIC_ACQUIRE,
    ATOMIC_RELEASE,
    ATOMIC_ACQ_REL,
    ATOMIC_SEQ_CST
} atomic_order_t;

#if defined (COMPILER_GCC) || defined(COMPILER_LLVM)
    #define fx_atomic_store(type) \
        inline void atomic_store(type *ptr, type value) {               \
            __atomic_store_n(ptr, value, __ATOMIC_SEQ_CST);             \
    }
#elif defined(COMPILER_MSVC)
        #define fx_atomic_store(type) \
        inline void atomic_store(type *ptr, type value) {               \
        ;;                                                              \
        }
#endif



#endif
