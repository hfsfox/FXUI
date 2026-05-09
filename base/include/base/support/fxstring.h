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

#ifndef __FXSTRING_H__
#define __FXSTRING_H__

#include <fxsystypes.h>
#include <fxendian.h>

namespace FX
{
    class FXString
    {
    public:
        explicit FXString();
        ~FXString();
    public:
        /** Get the length of the string
         * @return the length of the string
         **/
        inline size_t length() const { return string_len; }
        /**
         * Set the length of the string, allows only to cut data from tail
         * @param length the length of the string
         * @return the length of the string after applied operarion
         **/
        inline size_t set_length(size_t length) { return \
            (string_len >= length) ? string_len = length : string_len; }
        /** Check whether the string is emtpy
         * @return true if string is empty
         **/
        inline bool is_empty() const { return string_len <= 0; }
    protected:
        size_t string_len;
    };
}

#endif
