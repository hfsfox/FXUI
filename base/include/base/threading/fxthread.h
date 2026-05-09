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

#ifndef     __FXTHREAD_H__
#define     __FXTHREAD_H__

#include <base/threading/fxrunnabletask.h>
#include <base/common/fxplatformdefs.h>
#include <base/stdlib/fxstatuscode.h>

#include <base/threading/fxthreadtypes.h>

#include <stdint.h>

// platform specific
#if defined (PLATFORM_UNIX_COMPATIBLE)
    #include <pthread.h>
#elif defined (PLATFORM_WINDOWS)
    #include <windows.h>
    #include <processthreadsapi.h>
    //#include <winbase.h>
#elif defined (PLATFORM_HAIKU)
    #include <kernel/OS.h>
#endif
//end platform specific

/**
 * Class abstraction for wrapping native threading
**/

namespace
{
    /*#if defined(PLATFORM_WINDOWS)
        HANDLE  hThread;        // Windows threads
    #else
        pthread_t   hThread;        // POSIX threads
    #endif*/
    #if !defined(PLATFORM_WINDOWS)
        ::pthread_t rThread;
    #else
        ::HANDLE rThread;
    #endif
}

namespace fx
{

    #if defined (PLATFORM_WINDOWS)
        typedef /*umword_t*/ uint64_t               thread_id_t;
    #elif defined (PLATFORM_UNIX_COMPATIBLE)
        typedef /*umword_t*/ uint64_t               thread_id_t;
    #endif

    /**
    * Thread procedure that can be launched
    * @param arg additional argument passed to a thread procedure
    * @return status of thread execution
    **/
        typedef status_code_t (* thread_proc_t)(void* arg);
}

namespace FX
{
    /*
    template <class P> class FXThread
    {
        public:
            FXThread(const P &param, const char &name,
                     fx::thread_priority_t = FX_NORMAL_PRIORITY)
            {
            };
            virtual ~FXhread()
            {
            };
        public:
            virtual status_code_t Start()
            {
                return fx::FX_STATUS_OK;
            };
            virtual status_code_t Resume()
            {
                return fx::FX_STATUS_OK;
            };
		`   virtual status_code_t Suspend()
            {
                return fx::FX_STATUS_OK;
            };
            virtual status_code_t Join()
            {
                return fx::FX_STATUS_OK;
            };
            virtual status_code_t Cancel()
            {
                return fx::FX_STATUS_OK;
            };

            virtual thread_id_t GetThreadID()
            {
                thread_id_t thr_id_result = 0;
                return thr_id_result;
            };

        private:
    };
    */
    class FXThread: public FXRunnableTask
    {
        public:
            explicit FXThread()
            {
                running = false;
                thread_exec_result = fx::status::FX_STATUS_OK;
            };
            explicit FXThread(fx::thread_proc_t proc)
            {
                thread_exec_result = fx::status::FX_STATUS_OK;
            };
            explicit FXThread(fx::thread_proc_t proc, void *arg)
            {
                thread_exec_result = fx::status::FX_STATUS_OK;
            };
            explicit FXThread(FX::FXRunnableTask *runnable_task)
            {
                thread_exec_result = fx::status::FX_STATUS_OK;
            };
            virtual ~FXThread()
            {
            };
        public:
            virtual status_code_t Run()
            {
                running = true;
                return fx::status::FX_STATUS_OK;
            };
            virtual status_code_t Cancel()
            {
                return fx::status::FX_STATUS_OK;
            };
            virtual status_code_t ThreadStatus()
            {
                if(!running == true)
                    fx::status::FX_STATUS_UNSPECIFIED;
                else
                return fx::status::FX_STATUS_RUNNING;
            };
        private:
            static thread_local FXThread     *thr_ptr;
        protected:
            typedef struct proc_binding_t
                {
                    fx::thread_proc_t   proc;
                    union
                    {
                        FX::FXRunnableTask* runnable_task;
                        void* arg;
                    };
                } proc_binding_t;
                status_code_t thread_exec_result;
                bool running;
    };

}

#endif
