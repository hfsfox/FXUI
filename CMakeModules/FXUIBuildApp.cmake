#=============================================================================
# SPDX-FileCopyrightText: 2025 Kravchuk Roman
#
# SPDX-License-Identifier: MIT
#=============================================================================

#
# - FXUI build apps module for CMake
#

function(build_app TARGET)
    foreach (arg ${ARGN})
    list(APPEND REAL_SOURCES ${arg})
    endforeach()
    add_executable(${TARGET} ${REAL_SOURCES})
endfunction()
