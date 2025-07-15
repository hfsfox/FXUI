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

#ifndef __FXPLATFORMDEFS_H__
#define __FXPLATFORMDEFS_H__
#endif

#if defined(__unix__) || defined(unix) || defined(__unix)
    #define PLATFORM_UNIX
#endif /* __unix__ */

#if defined(__sysv__) || defined(__SVR4) || defined (__svr4__)
    #define PLATFORM_UNIX
#endif

#if defined(__sun__) || defined(__sun) || defined(sun)
    # if defined(__SVR4) || defined(__svr4__)
        #define PLATFORM_SOLARIS
    #elif defined(__illumos__)
        #define PLATFORM_ILLUMOS
        #define PLATFORM_SOLARIS
    # else
        #define PLATFORM_SUNOS
    # endif
#endif /* __solaris__ */

#if defined (__Lynx__)
    #define PLATFORM_LYNXOS
#endif /*__lynxos__*/

#if defined (__minix)
    #define PLATFORM_MINIX
#endif /*__minix__*/

#if defined (__gnu_hurd__) || defined(__GNU__)
    #define PLATFORM_GNU_HURD
#endif /*__gnu_hurd__*/

#if defined(__linux__) || defined(__linux) || defined(linux) || defined (__gnu_linux__) && (!defined(__ANDROID__) || !defined (__ANDROID_API__))
    #define PLATFORM_LINUX
#endif /* __linux__ */

#if defined (__ANDROID__) || defined (__ANDROID_API__) && !defined (PLATFORM_LINUX)
    #include <android/api-level.h>
    #define PLATFORM_ANDROID
#endif /* __android__ */

#if defined (sco) || defined (_UNIXWARE7)
    #define PLATFORM_UNIXWARE
#endif

#if defined (__osf__) || defined (__osf)
    #define PLATFORM_OSF_TRU64
#endif

#if defined (__sgi) || defined (sgi) || defined (_SYSTYPE_SVR4)
    #define PLATFORM_IRIX
#endif /* __irix__ */

#if defined (__hpux) || defined (_hpux) || defined (hpux)
    #define PLATFORM_UNIX
#endif /* __hp_ux__ */

#if defined (_AIX) || defined (__TOS_AIX__) || defined (_AIX3) || defined (_AIX32) \
|| defined (_AIX41) || defined (_AIX43)
    #define PLATFORM_UNIX
#endif /* __aix__ */

#if defined(__serenity__)
    #define PLATFORM_UNIX
#endif /* __serenityos__ */

#if defined(__FreeBSD__)
    #define PLATFORM_BSD
#endif /* __freebsd__ */

#if defined(__OpenBSD__)
    #define PLATFORM_BSD
#endif /* __openbsd__ */

#if defined(__NetBSD__) || defined (__NETBSD__)
    #define PLATFORM_BSD
#endif /* __openbsd__ */

#if defined(__DragonFly__)
    #define PLATFORM_BSD
#endif /* __dragonflybsd__ */

#if defined (__QNX__) || defined (__QNXNTO__) || defined (BBNDK_VERSION_CURRENT)
    #define PLATFORM_QNX
#endif

#if defined (__VXWORKS__) || defined (__vxworks) || defined (__VXWORKS)
    #define PLATFORM_VXWORKS
#endif

#if defined(__bsd__) || defined(__bsd) || defined(__FreeBSD__) || defined(__OpenBSD__) \
|| defined(freebsd) || defined(openbsd) || defined(bsdi) || defined(__darwin__) || defined(_SYSTYPE_BSD)
    #define PLATFORM_BSD
#endif /* __unix__ */

#if defined(__macosx__) || defined(__APPLE__) || defined(__MACH__) || defined(__DARWIN__)
    #include <Availability.h>
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_IOS
    #elif TARGET_OS_MACCATALYST == 1
         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
    #elif TARGET_OS_IPHONE == 1
        // iOS, tvOS, or watchOS device
        #define PLATFORM_IOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_MACOSX
    #else
    #   warning "Unknown Apple platform"
    #endif
#endif /* __macosx__ */

#if defined(__fuchsia__) || defined (__Fuchsia__)
    #define PLATFORM_FUCHSIA
#endif

#if defined(EPLAN9)
    #define PLATFORM_PLAN9
#endif

#if defined (__SYLLABLE__)
    #define PLATFORM_SYLLABLE
#endif

#if defined (__BEOS__)
    #define PLATFORM_BEOS
#endif /* __beos__ */

#if defined (__HAIKU__)
    #define PLATFORM_HAIKU
#endif /* __haiku__ */

#if defined (__SYMBIAN32__)
    #define PLATFORM_SYMBIAN
#endif

#if defined(PLATFORM_UNIX) || defined(PLATFORM_LINUX) || defined(PLATFORM_MACOSX) || defined(PLATFORM_BSD) \
|| defined(PLATFORM_HAIKU) || defined(PLATFORM_BEOS) || defined(PLATFORM_SOLARIS) || defined(PLATFORM_QNX) \
|| defined(PLATFORM_IRIX) || defined(PLATFORM_ANDROID) || defined(PLATFORM_LYNXOS) || defined(PLATFORM_FUCHSIA)\
|| defined(PLATFORM_GNU_HURD) || defined(PLATFORM_SYLLABLE) || defined(PLATFORM_PLAN9) || defined(PLATFORM_OSF_TRU64)\
|| defined(PLATFORM_MINIX) || defined(PLATFORM_SUNOS) || defined(PLATFORM_IOS) || defined(PLATFORM_VXWORKS)
    #define PLATFORM_UNIX_COMPATIBLE
#endif /* unix-compatible platforms */

#if defined (__riscos) || defined (__RISCOS__) || defined (__riscos__)
    #define PLATFORM_RISCOS
#endif

#if defined (macintosh) || defined(Macintosh)
    #define PLATFORM_MACOS
#endif

#if defined (__amiga)
    #define PLATFORM_AMIGA
#endif

#if defined (__os4__) || defined (__amigaos4__)
     #define PLATFORM_AMIGA
    #define PLATFORM_AMIGAOS4
#endif

#if defined (__MORPHOS__)
    #define PLATFORM_AMIGA
    #define PLATFORM_MORPHOS
#endif

#if defined (__AROS__)
    #define PLATFORM_AMIGA
    #define PLATFORM_AROS
#endif

#if defined(PLATFORM_AROS) || defined (PLATFORM_MORPHOS) || defined (PLATFORM_AMIGAOS4)
    #define PLATFORM_AMIGA_COMPATIBLE
#endif

#if defined (__VMS) || defined (VMS) || defined (__VMS_VER)
    #define PLATFORM_VMS
#endif

#if defined (__os2__)
    define PLATFORM_OS2
#endif /* __os2__ */

#if defined(__WINDOWS__) || defined(__WIN32__) || defined(__WIN64__) || defined(_WIN64) || defined(_WIN32) \
|| defined(__WINNT) || defined(__WINNT__)
    #define PLATFORM_WINDOWS
#endif /* __windows__ */

#if defined (_WIN32_WCE)
    #define PLATFORM_WINDOWS_CE
#endif /*__windows_ce__*/



#define STRING_ENDL_UNIX                 "\n"
#define STRING_ENDL_WIN                   "\n\n"

#if defined(PLATFORM_UNIX_COMPATIBLE) ||  !defined (PLATFORM_AMIGA) || !defined(PLATFORM_MACOSX)
      #define FILE_SEPARATOR_C            '/'
      #define FILE_SEPARATOR_S            "/"
      #define FILE_SYSTEM_CASE_SENSE      1
      #define FILE_LIBRARY_EXT_S          ".so"
      #define STRING_ENDL                 STRING_ENDL_UNIX
#elif defined (PLATFORM_AMIGA) || defined (PLATFORM_AMIGA_COMPATIBLE)
      #define FILE_SEPARATOR_C            '/'
      #define FILE_SEPARATOR_S            "/"
      #define FILE_SYSTEM_CASE_SENSE      1
      #define FILE_LIBRARY_EXT_S          ".library"
      #define STRING_ENDL                 STRING_ENDL_UNIX
#elif defined (PLATFORM_RISCOS)
      #define FILE_SEPARATOR_C            '.'
      #define FILE_SEPARATOR_S            "."
      #define FILE_SYSTEM_CASE_SENSE      0
      #define FILE_LIBRARY_EXT_S          ".so"
      #define STRING_ENDL                 STRING_ENDL_UNIX
#elif defined(PLATFORM_MACOSX)
      #define FILE_SEPARATOR_C            '/'
      #define FILE_SEPARATOR_S            "/"
      #define FILE_SYSTEM_CASE_SENSE      1
      #define FILE_LIBRARY_EXT_S          ".dylib"
      #define STRING_ENDL                 STRING_ENDL_UNIX
#elif defined(PLATFORM_WINDOWS) || defined(PLATFORM_WINDOWS_CE) || defined(PLATFORM_OS2)
      #define FILE_SEPARATOR_C            '\\'
      #define FILE_SEPARATOR_S            "\\"
      #define FILE_SYSTEM_CASE_SENSE      0
      #define FILE_LIBRARY_EXT_S          ".dll"
      #define STRING_ENDL                 STRING_ENDL_WIN
#endif
