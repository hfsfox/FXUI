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

#ifndef __FXDEBUG_H__
#define __FXDEBUG_H__

//#include <fxstatuscode.h>
#include <stdio.h>
//#include <unistd.h>
#include <stdarg.h>

//namespace
//{
//    #ifdef FX_TRACEFILE
//        #define FX_LOG_FD              ::fx::log_fd
//    #else
//        #define FX_LOG_FD              /*stderr*/ stdout
//    #endif
//}

//#define slashn "\"
/*
#define dbg_log(msg " ", ...) do \
        { \
            fprintf(FX_LOG_FD, msg, ## __VA_ARGS__); \
            fflush(FX_LOG_FD); \
        } while(0)
*/

//#define debug_loop             do {} while(0)
/*
namespace dbg
{
    int cprintf(const char *fmt...)
    {
        va_list ap;
        va_start(ap, fmt);

        int r = vprintf(fmt, ap);

        va_end(ap);
        return r;
    };
}
*/

//#define dbg_log(msg, ...) dbg::cprintf( " " msg "\n", ## __VA_ARGS__);

namespace fx
{
    namespace debug
    {
        /**
         * Get environment variable
         * @param name environment variable name
         * @param dst string to store environment variable value, NULL for
         *  check-only
         * @return status of operation or STATUS_NOT_FOUND if there is no
         *  environment variable
         */
        //status_t get_env_var(const FXString *name, FXString *dst);
        /**
         * Get environment variable
         * @param name environment variable name in UTF-8
         * @param dst string to store environment variable value, NULL for
         *  check-only
         * @return status of operation or STATUS_NOT_FOUND if there is no
         *  environment variable
         */
        //status_code_t get_env_var(const char* name, /*FXString*/ const char* dst);
        //#define dbg_log(msg, ...) {fprintf(FX_LOG_FD, msg, ## __VA_ARGS__); fflush(FX_LOG_FD);}
        //fprintf(FX_LOG_FD, msg)
        //#define dbg_log(msg, ...) { fprintf(FX_LOG_FD, msg); /*fflush(FX_LOG_FD);*/ }
        //dbg_log()
        //#define dbg_log dbg_log
        /*dbg_log(msg, ...)
        {
            dbg_log(msg,...)
        }*/
        //#define dbg_log(msg, ...)         dbg::cprintf(msg "\n", ## __VA_ARGS__)
        //#define dbg_log(msg, ...) dbg::cprintf(msg "\n", ## __VA_ARGS__)
        /*
        int cprintf(const char *fmt...)
        {
            va_list ap;
            va_start(ap, fmt);

            int r = vprintf(fmt, ap);

            va_end(ap);
            return r;
        };
        */
        //#define lsp_printf(msg, ...)        cprintf(msg "\n", ## __VA_ARGS__)
        //debug_log(msg, ...)
        //{
        //    dbg::cprintf( " " msg "\n", errno/*## __VA_ARGS__*/);
        //}
    }
}

#endif
