#ifndef _LEARN_X11_WSING_HPP_
#define _LEARN_X11_WSING_HPP_


#include <string>
#include "wnd.hpp"

namespace x11
{
    #include <X11/Xlib.h>
    class Wsng;

    class Wsng
    {
        static Wnd wnd;
        Wsng();
        static Wsng& instance();
        void open();
        void close();
    public:
        ~Wsng();
        static Wnd* create();
        static Wnd* create(std::string rename);
        static Wnd* window();
        static void run();

        Wsng(Wsng const&) = delete;
        void operator=(Wsng const&) = delete;
    };
}


#endif // _LEARN_X11_WSING_HPP_
