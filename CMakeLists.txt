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
        DESCRIPTION "Code for lab works by student ONPU group AT-221"
        HOMEPAGE_URL "http://github.com/hfsfox/fxui/"
        LANGUAGES OBJC OBJCXX CXX C ASM
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

if(LINUX)
    if(BACKEND_WAYLAND)
        add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_WAYLAND
    )
    endif()
    if(BACKEND_X11)
        add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_X11
    )
    endif()
endif()

if(HAIKU)
    add_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC
	BACKEND_BEAPI
    )
endif()

if(LINUX)
    find_package(PkgConfig REQUIRED)
    find_package(X11 REQUIRED)
    find_package(Freetype REQUIRED)
endif()
if(LINUX)
    set(FXUI_FREETYPE_INCLUDE
        ${FREETYPE_INCLUDE_DIRS}
        /usr/include/freetype2
    )
else()
    set(FXUI_FREETYPE_INCLUDE
    )
endif()

include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    include/base
    include/widgets
    include/widgets/dialogs
    #src/platform/haiku
    ${FXUI_FREETYPE_INCLUDE}
    #/usr/include/freetype2
    )

set(FXUI_BASE_SOURCES
    src/fxui/fxdisplay.cpp
    src/fxui/fxwindow.cpp
    src/fxui/fxbitmap.cpp
    src/fxui/fxfont.cpp
)

set(FXUI_WIDGET_SOURCES
    src/fxui/widgets/fxbutton.cpp
    src/fxui/widgets/fxcheckbox.cpp
    src/fxui/widgets/fxmenubar.cpp
    src/fxui/widgets/fxprogressbar.cpp
    src/fxui/widgets/fxradiobutton.cpp
    src/fxui/widgets/fxslider.cpp
    src/fxui/widgets/fxtextfield.cpp
    src/fxui/widgets/fxtextview.cpp
    src/fxui/widgets/fxtoolbar.cpp
)

set(FXUI_WIDGET_DIALOG_SOURCES
)

set(FXUI_SOURCES
    ${FXUI_BASE_SOURCES}
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
elseif(WIN32)
    set(PLATFORM_SOURCES
    )
endif()

add_executable(${CMAKE_PROJECT_NAME}_example
    src/test/example.cpp
   ${FXUI_SOURCES}
   ${PLATFORM_SOURCES}
    )

add_executable(${CMAKE_PROJECT_NAME}_init_dpy
    src/test/example_init_dpy.cpp
   ${FXUI_SOURCES}
   ${PLATFORM_SOURCES}
    )

add_executable(${CMAKE_PROJECT_NAME}_init_messagebox
    src/test/example_init_messagebox.cpp
   ${FXUI_SOURCES}
   ${PLATFORM_SOURCES}
    )

if(LINUX)
    if (BACKEND_X11)
        target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC Xext X11 Xpm GL GLU GLX Xft ${FREETYPE_LIBRARIES})
        target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC Xext X11 Xpm GL GLU GLX Xft ${FREETYPE_LIBRARIES})
        target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC Xext X11 Xpm GL GLU GLX Xft ${FREETYPE_LIBRARIES})
    endif()
    if (BACKEND_WAYLAND)
        target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC wayland-client wayland-cursor Xpm GL GLU ${FREETYPE_LIBRARIES})
        target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC wayland-client wayland-cursor Xpm GL GLU ${FREETYPE_LIBRARIES})
        target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC wayland-client wayland-cursor Xpm GL GLU ${FREETYPE_LIBRARIES})
    endif()
 elseif(WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC user32 gdi32 opengl32)
    target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC user32 gdi32 opengl32)
    target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC user32 gdi32 opengl32)
elseif(HAIKU)
   target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC be root game tracker textencoding GL stdc++ supc++)
   target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC be root game tracker textencoding GL stdc++ supc++)
   target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC be root game tracker textencoding GL stdc++ supc++)
endif()
