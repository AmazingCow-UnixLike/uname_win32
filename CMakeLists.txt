##~---------------------------------------------------------------------------##
##                     _______  _______  _______  _     _                     ##
##                    |   _   ||       ||       || | _ | |                    ##
##                    |  |_|  ||       ||   _   || || || |                    ##
##                    |       ||       ||  | |  ||       |                    ##
##                    |       ||      _||  |_|  ||       |                    ##
##                    |   _   ||     |_ |       ||   _   |                    ##
##                    |__| |__||_______||_______||__| |__|                    ##
##                             www.amazingcow.com                             ##
##  File      : CMakeLists.txt                                                ##
##  Project   : uname_win32                                                   ##
##  Date      : Jan 26, 2018                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : n2omatt <n2omatt@amazingcow.com>                              ##
##  Copyright : AmazingCow - 2018                                             ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

cmake_minimum_required(VERSION 3.5)
project(uname)

##----------------------------------------------------------------------------##
## Compiler Definitions                                                       ##
##----------------------------------------------------------------------------##
set(CMAKE_CXX_STANDARD 11)


##----------------------------------------------------------------------------##
## Include Directories                                                        ##
##----------------------------------------------------------------------------##
include_directories(
    libs/acow_cpp_goodies
    libs/acow_nt_posix
    libs/CoreAssert
    libs/CoreLog
    libs/CoreOS
    libs/CoreString
    libs/libtermcolor
)


##----------------------------------------------------------------------------##
## Source Files                                                               ##
##----------------------------------------------------------------------------##
set(SOURCE_FILES
   libs/acow_nt_posix/acow/src/win32/utsname.cpp

   libs/CoreAssert/CoreAssert/src/private/PrivateHelpers.cpp

   libs/CoreLog/CoreLog/src/Log.cpp
   libs/CoreLog/CoreLog/src/Logger.cpp
   libs/CoreLog/CoreLog/src/private/os_functions.cpp

   libs/CoreOS/CoreOS/src/OS.cpp

   libs/CoreString/CoreString/libs/asprintf/asprintf.cpp
   libs/CoreString/CoreString/libs/asprintf/vasprintf-c99.cpp
   libs/CoreString/CoreString/src/CoreString.cpp

   libs/libtermcolor/termcolor/src/Config.cpp
   libs/libtermcolor/termcolor/src/Functions.cpp

   src/main.cpp
)


##----------------------------------------------------------------------------##
## Executable Definitions                                                     ##
##----------------------------------------------------------------------------##
add_executable(uname ${SOURCE_FILES})