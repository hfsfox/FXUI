#=============================================================================
# SPDX-FileCopyrightText: 2025 Kravchuk Roman
#
# SPDX-License-Identifier: MIT
#=============================================================================

#
# - FXUI
#

cmake_minimum_required(VERSION 3.30)

project("FXUI"
        VERSION 0.0.58
        DESCRIPTION "Code for lab works by student ONPU group AT-221"
        HOMEPAGE_URL "http://github.com/hfsfox/fxui/"
        LANGUAGES CXX C ASM
        )

if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message(STATUS "Target platform:        ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler:               ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Target arch:            ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Build type:             ${CMAKE_BUILD_TYPE}")
message(STATUS "Build C flags:          ${CMAKE_C_FLAGS}")
message(STATUS "Build CXX flags:        ${CMAKE_CXX_FLAGS}")
message(STATUS "Link flags:             ${CMAKE_C_LINK_FLAGS}")

include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    include
    src/platform/haiku
    )


set(FXUI_SOURCES
    src/fxui/fxdisplay.cpp
    src/fxui/fxwindow.cpp
    src/fxui/fxbitmap.cpp
    src/fxui/fxfont.cpp
)

if(HAIKU)
    set(PLATFORM_SOURCES
        src/fxui/platform/haiku/BApplicationInstance.cpp
        src/fxui/platform/haiku/BeAPIWindow.cpp
        src/fxui/platform/haiku/BeAPIView.cpp
    )
elseif(LINUX)
    set(PLATFORM_SOURCES
    )
elseif(WIN32)
    set(PLATFORM_SOURCES
    )
endif()

add_executable(${CMAKE_PROJECT_NAME}
    src/test/example.cpp
   ${FXUI_SOURCES}
   ${PLATFORM_SOURCES}
    )

if(LINUX)
 target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Xext X11 Xpm GL GLU GLX )
 elseif(WIN32)
 target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC user32 gdi32 opengl32)
elseif(HAIKU)
   target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC be root game tracker textencoding GL stdc++ supc++)
endif()
