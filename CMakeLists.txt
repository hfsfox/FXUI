#=============================================================================
# SPDX-FileCopyrightText: 2025 Kravchuk Roman aka hfsfox
#
# SPDX-License-Identifier: MIT
#=============================================================================

#
# - FXUI: Graphical User Interface Framework
#

cmake_minimum_required(VERSION 3.30)

project("FXUI"
        VERSION 0.0.58
        DESCRIPTION "FXUI: Graphical User Interface Framework"
        HOMEPAGE_URL "http://github.com/hfsfox/fxui/"
        )

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    project(${CMAKE_PROJECT_NAME} LANGUAGES CXX OBJCXX OBJC C ASM)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR WIN32 OR WIN64)
    project(${CMAKE_PROJECT_NAME} LANGUAGES C CXX ASM)
else()
    # Default languages for other systems
    project(${CMAKE_PROJECT_NAME} LANGUAGES C CXX ASM)
endif()

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

set(CMAKE_MODULE_PATH "${${PROJECT_NAME}_SOURCE_DIR}/cmake")

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" OFF)
option(BUILD_R3D_WIDGETS "Build 3D/GL widgets" ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Enable all warnings in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-Wall -Wextra -Wpedantic)
    elseif(MSVC)
        add_compile_options(/W4)
    endif()
endif()

if (MSVC)
    add_compile_definitions( ${CMAKE_PROJECT_NAME} PUBLIC
    UNICODE=1
    _UNICODE=1
    )
        #add_compile_options(/MT)
    add_compile_options(/MP)
    add_compile_options(/nologo)
    add_compile_options(/std:c++14)
        #add_compile_options(/subsystem:windows)
    add_compile_options("$<$<CONFIG:Release>:/O2>")
        #target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W4)
        #set_property(${CMAKE_PROJECT_NAME} PUBLIC STRING "/Ox /Ob2 /Oi /Ot /GF /Zc:wchar_t /MT")
        #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows")
        #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_definitions( ${CMAKE_PROJECT_NAME} PUBLIC
    UNICODE=1
    _UNICODE=1
    )
endif()

if(APPLE)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_COCOA
    )
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework AppKit -framework Foundation")
endif()

if(LINUX OR UNIX AND NOT APPLE AND NOT HAIKU AND NOT QNX)
    find_package(PkgConfig REQUIRED)
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(Freetype REQUIRED)

    message("Found X11 Libraries.")
    message("X11 includes: ${X11_INCLUDE_DIR}")
    message("X11 Libraries: ${X11_LIBRARIES}")
    message("XPM includes: ${X11_Xpm_INCLUDE_PATH}")
    message("XPM Libraries: ${X11_Xpm_LIB}")
    message("Found OpenGL Libraries.")
    message("OpenGL includes: ${OPENGL_INCLUDE_DIR}")
    message("OpenGL Libraries: ${OPENGL_LIBRARIES}")
endif()
if(LINUX OR UNIX AND NOT APPLE AND NOT HAIKU)
    set(FXUI_FREETYPE_INCLUDE
        ${FREETYPE_INCLUDE_DIRS}
        /usr/include/freetype2
    )
else()
    set(FXUI_FREETYPE_INCLUDE
    )
endif()

if(UNIX AND NOT APPLE AND NOT HAIKU)
    if(BACKEND_WAYLAND)
        add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_WAYLAND=1
    )
    message("Build for Wayland backend.")
    endif()
    if(BACKEND_X11)
        add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_X11=1
    )
    message("Build for X11 backend.")
    endif()
elseif(HAIKU)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_BEAPI=1
    )
elseif(QNX)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
    BACKEND_PHOTON=1
    )
elseif(WIN32 OR WIN64 OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_WINAPI=1
    )
endif()

set(FXUI_BASE_INCLUDE
    base/include
)
set(FXUI_SUPPORT_INCLUDE
    support/include
)
set(FXUI_GUI_INCLUDE
    gui/include
)
set(FXUI_WIDGET_INCLUDE
    widget/include
)
set(FXUI_R3D_INCLUDE
    #widget/include
)

include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${FXUI_BASE_INCLUDE}
    ${FXUI_GUI_INCLUDE}
    ${FXUI_SUPPORT_INCLUDE}
    )

# build information
message(STATUS "Target platform:        ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler:               ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Target arch:            ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Build type:             ${CMAKE_BUILD_TYPE}")
message(STATUS "Build C flags:          ${CMAKE_C_FLAGS}")
message(STATUS "Build CXX flags:        ${CMAKE_CXX_FLAGS}")
message(STATUS "С Link flags:           ${CMAKE_C_LINK_FLAGS}")
message(STATUS "СXX Link flags:         ${CMAKE_CXX_LINK_FLAGS}")
message(STATUS "Build shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "Build 3D/GL widgets:    ${BUILD_R3D_WIDGETS}")

set(FXUI_BASE_SRC
    base/src/base/app/fxapplication.cpp
    base/src/base/stdlib/fxstatuscode.cpp
    base/src/base/threading/fxthread.cpp
    )
set(FXUI_GUI_SRC
    )
set(FXUI_SUPPORT_SRC
    support/src/support/fxeventhandler.cpp
    )

set(FXUI_SOURCES
    ${FXUI_BASE_SRC}
    ${FXUI_SUPPORT_SRC}
    #${FXUI_BASE_SOURCES}
    #${FXUI_LAYOUT_SOURCES}
    #${FXUI_WIDGET_SOURCES}
    #${FXUI_WIDGET_DIALOG_SOURCES}
)

add_library(${CMAKE_PROJECT_NAME} STATIC
    ${FXUI_SOURCES}
    )

if(LINUX)
    if (BACKEND_X11)
        target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
        ${X11_LIBRARIES}
        ${X11_Xpm_LIB}
        ${OPENGL_LIBRARIES}
        Xft
        ${FREETYPE_LIBRARIES}
        )
    endif()
    if (BACKEND_WAYLAND)
        target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
        wayland-client
        wayland-cursor
        Xpm
        GL
        GLU
        ${FREETYPE_LIBRARIES}
        )
    endif()
elseif(WIN32)
    set(DWMAPI_LIBS
    dwmapi
    uxtheme
    )
    target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
     user32
     gdi32
     opengl32
     ${DWMAPI_LIBS}
     )
elseif(HAIKU)
   target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    be
    root
    game
    tracker
    textencoding
    GL
    stdc++
    supc++
    )
endif()

add_subdirectory(base)
add_subdirectory(gui)

