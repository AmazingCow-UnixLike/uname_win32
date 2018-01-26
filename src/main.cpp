//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : main.cpp                                                      //
//  Project   : uname_win32                                                   //
//  Date      : Jan 26, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// std
#include <iostream>
// CoreOS
#include "CoreOS/CoreOS.h"
#include "CoreLog/CoreLog.h"


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define PROGRAM_NAME    "uname"
#define COPYRIGHT_YEARS "2018"

#define COW_UNAME_WIN32_VERSION_MAJOR    "0"
#define COW_UNAME_WIN32_VERSION_MINOR    "1"
#define COW_UNAME_WIN32_VERSION_REVISION "0"

#define COW_UNAME_WIN32_VERSION           \
        COW_UNAME_WIN32_VERSION_MAJOR "." \
        COW_UNAME_WIN32_VERSION_MINOR "." \
        COW_UNAME_WIN32_VERSION_REVISION



//----------------------------------------------------------------------------//
// Types                                                                      //
//----------------------------------------------------------------------------//
enum {
    FLAG_M = 1 << 0,
    FLAG_N = 1 << 1,
    FLAG_R = 1 << 2,
    FLAG_S = 1 << 3,
    FLAG_V = 1 << 4,
    FLAG_A = FLAG_M | FLAG_N | FLAG_R | FLAG_S | FLAG_V
};


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
void append(std::string &str, const std::string &contents) noexcept
{
    if(!contents.empty())
        str += contents + " ";
}

void show_help() noexcept
{
    std::string msg = R"(Usage: uname [OPTION]...
Print certain system information.  With no OPTION, same as -s.

  -a, --all                print all information, in the following order,

  -s, --kernel-name        print the kernel name
  -n, --nodename           print the network node hostname
  -r, --kernel-release     print the kernel release
  -v, --kernel-version     print the kernel version
  -m, --machine            print the machine hardware name

      --help     display this help and exit
      --version  output version information and exit
)";

    std::cout << msg << std::endl;
    exit(0);
}

void show_version() noexcept
{
    std::string msg = R"(%s- %s - N2OMatt <n2omatt@amazingcow.com>
Copyright(c) %s - Amazing Cow
This is a free software(GPLv3) - Share / Hack it
Check www.amazingcow.com for more :)
    )";

    printf(
        msg.c_str(),
        PROGRAM_NAME,
        COW_UNAME_WIN32_VERSION,
        COPYRIGHT_YEARS
    );
    exit(0);
}

//----------------------------------------------------------------------------//
// Entry Point                                                                //
//----------------------------------------------------------------------------//
//http://pubs.opengroup.org/onlinepubs/9699919799/utilities/uname.html
int main(int argc, char *argv[])
{
    int flags = 0;
    if(argc == 1)
    {
        flags = FLAG_S;
    }
    else
    {
        for(int i = 1; i < argc; ++i)
        {
            //------------------------------------------------------------------
            // Help / Version.
            if     (strcmp("--help",    argv[i]) == 0) show_help   ();
            else if(strcmp("--version", argv[i]) == 0) show_version();
            //------------------------------------------------------------------
            // Flags.
            else if(strcmp("-m", argv[i]) == 0) flags |= FLAG_M;
            else if(strcmp("-n", argv[i]) == 0) flags |= FLAG_N;
            else if(strcmp("-r", argv[i]) == 0) flags |= FLAG_R;
            else if(strcmp("-s", argv[i]) == 0) flags |= FLAG_S;
            else if(strcmp("-v", argv[i]) == 0) flags |= FLAG_V;
            else if(strcmp("-a", argv[i]) == 0) flags |= FLAG_A;
            //------------------------------------------------------------------
            // Unhandled flag.
            else CoreLog::Error("Invalid flag: %s", argv[i]);
        }
    }

    //--------------------------------------------------------------------------
    // Process the info.
    std::string str;

    if(flags & FLAG_S) append(str, CoreOS::OSInfo::OperatingSystem());
    if(flags & FLAG_N) append(str, CoreOS::OSInfo::Nodename       ());
    if(flags & FLAG_R) append(str, CoreOS::OSInfo::KernelRelease  ());
    if(flags & FLAG_V) append(str, CoreOS::OSInfo::KernelVersion  ());
    if(flags & FLAG_M) append(str, CoreOS::OSInfo::Machine         ());

    //--------------------------------------------------------------------------
    // Print,
    std::cout << str << std::endl;

    return 0;
}