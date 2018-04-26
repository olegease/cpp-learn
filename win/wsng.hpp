#ifndef _LEARN_WIN_WSNG_HPP_
#define _LEARN_WIN_WSNG_HPP_

#include "wnd.hpp"

extern "C" {
    #include "windows.h"
}

namespace win
{
    class Wsng
    {
        static Wnd wnd;
        Wsng();
        static Wsng& instance();
        static long __stdcall WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp);
        void open();
        void close();
    public:
        ~Wsng();
        static Wnd* window();
        static Wnd* create();
        static void run();
    };
}

#endif // _LEARN_WIN_WSNG_HPP_
