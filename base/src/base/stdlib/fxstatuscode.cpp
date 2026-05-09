#include <base/stdlib/fxstatuscode.h>

namespace
{
    const char *status_descriptions[] =
    {
        "OK",
        "NULL",
        "Unspecified",
        "Loading",
        "In process",
        "Running",
        "Unknown error",
        "No memory",
        "Not found",
        "I/O error",
        "No file",
        "End of file",
        "Bad arguments",
        "Not implemented",
        //
        NULL
    };
}

namespace fx
{
    namespace status
    {
        const char* get_status(status_code_t code)
        {
            return ((code >= 0) && (code < FX_STATUS_TOTAL)) ? status_descriptions[code] : NULL;
        };
        bool status_is_success(status_code_t code)
        {
            return code == FX_STATUS_OK;
        };
        bool status_is_error(status_code_t code)
        {
            if (status_is_success(code))
                return true;

            return false;
        };
    }
}
