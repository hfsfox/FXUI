#=============================================================================
# SPDX-FileCopyrightText: 2025 Kravchuk Roman
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
        #LANGUAGES OBJC OBJCXX CXX C ASM
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

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_MODULE_PATH "${${PROJECT_NAME}_SOURCE_DIR}/CMakeModules")

include(FXUIBuildApp)

if(APPLE)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_COCOA
    )
    #set(CMAKE_C_FLAGS "-x objective-c")
    #set(CMAKE_CXX_FLAGS "-x objective-c++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework AppKit -framework Foundation")
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
endif()

if(HAIKU)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_BEAPI=1
    )
endif()

if(QNX)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
    BACKEND_PHOTON=1
    )
endif()

if(WIN32 OR WIN64 OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_WINAPI=1
    )
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

include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    include
    include/base
    include/widgets
    include/widgets/dialogs
    ${FXUI_FREETYPE_INCLUDE}
    )

set(FXUI_BASE_SOURCES
    src/fxui/fxapplication.cpp
    src/fxui/fxdisplay.cpp
    src/fxui/fxwindow.cpp
    src/fxui/fxbitmap.cpp
    src/fxui/fxfont.cpp
    src/fxui/fxview.cpp
)

set(FXUI_LAYOUT_SOURCES
)

set(FXUI_WIDGET_SOURCES
    src/fxui/widgets/fxwidget.cpp
    src/fxui/widgets/fxbutton.cpp
    src/fxui/widgets/fxcheckbox.cpp
    src/fxui/widgets/fxmenubar.cpp
    src/fxui/widgets/fxprogressbar.cpp
    src/fxui/widgets/fxradiobutton.cpp
    src/fxui/widgets/fxpopupmenu.cpp
    src/fxui/widgets/fxslider.cpp
    src/fxui/widgets/fxscrollbar.cpp
    src/fxui/widgets/fxtextfield.cpp
    src/fxui/widgets/fxtextview.cpp
    src/fxui/widgets/fxtoolbar.cpp
    src/fxui/widgets/fxstringview.cpp
)

set(FXUI_WIDGET_DIALOG_SOURCES
)

set(FXUI_SOURCES
    ${FXUI_BASE_SOURCES}
    ${FXUI_LAYOUT_SOURCES}
    ${FXUI_WIDGET_SOURCES}
    ${FXUI_WIDGET_DIALOG_SOURCES}
)

if(HAIKU)
    set(PLATFORM_SOURCES
        src/fxui/platform/haiku/BApplicationInstance.cpp
        src/fxui/platform/haiku/BeAPIWindow.cpp
        src/fxui/platform/haiku/BeAPIView.cpp
    )
elseif(LINUX)
    if (BACKEND_WAYLAND)
        set(
        PLATFORM_SOURCES
        src/fxui/platform/unix/wayland/WaylandAPIWindow.cpp
        src/fxui/platform/unix/wayland/protocols/xdg-shell-protocol.c
        src/fxui/platform/unix/wayland/protocols/xdg-decoration-unstable-v1.c
        )
    elseif(BACKEND_X11)
        set(
        PLATFORM_SOURCES
        src/fxui/platform/unix/x11/X11APIWindow.cpp
        )
    endif()
elseif(WIN32 OR WIN64 OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(PLATFORM_SOURCES
    )
elseif(APPLE)
    set(PLATFORM_SOURCES
    src/fxui/platform/macosx/MacOSXAPIWindow.mm
    src/fxui/plaform/macosx/MacOSXApplication.mm
    )
elseif(QNX)
    set(PLATFORM_SOURCES
    src/fxui/plaform/qnx/QNXAPIWindow.cpp
    )
endif()

message(STATUS "Target platform:        ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler:               ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Target arch:            ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Build type:             ${CMAKE_BUILD_TYPE}")
message(STATUS "Build C flags:          ${CMAKE_C_FLAGS}")
message(STATUS "Build CXX flags:        ${CMAKE_CXX_FLAGS}")
message(STATUS "Link flags:             ${CMAKE_C_LINK_FLAGS}")
message(STATUS "Build shared libraries: ${BUILD_SHARED_LIBS}")

#option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

add_subdirectory(src/test/app)
add_subdirectory(src/test/window)
add_subdirectory(src/test/widgets)

add_library(${CMAKE_PROJECT_NAME} STATIC
    ${FXUI_SOURCES}
    ${PLATFORM_SOURCES}
    )

#if(BUILD_SHARED_LIBS)
#  add_library(${CMAKE_PROJECT_NAME} SHARED 
#  ${FXUI_SOURCES}
#  ${PLATFORM_SOURCES}
#  )
#else()
#  add_library(${CMAKE_PROJECT_NAME} STATIC 
#  ${FXUI_SOURCES}
#  ${PLATFORM_SOURCES}
#  )
#endif()

add_executable(${CMAKE_PROJECT_NAME}_example
    ##WIN32
    src/test/example.cpp
    )

add_executable(${CMAKE_PROJECT_NAME}_init_dpy
    #WIN32
    src/test/example_init_dpy.cpp
    )

add_executable(${CMAKE_PROJECT_NAME}_init_messagebox
    src/test/example_init_messagebox.cpp
    )

add_executable(test_create_window
    src/test/test_create_window.cpp
    )

    target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC
    ${CMAKE_PROJECT_NAME} 
    )
    target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
    target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
    target_link_libraries( test_create_window PUBLIC
    ${CMAKE_PROJECT_NAME}
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
    #${CMAKE_PROJECT_NAME}
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
