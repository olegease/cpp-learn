#ifndef _LEARN_X11_WND_HPP_
#define _LEARN_X11_WND_HPP_

#include <string>
#include <iostream>
extern "C" {
    #include <X11/Xlib.h>
}


namespace x11
{
    class Wnd;
    typedef void (*fwndptr)(Wnd*);

    class Wnd
    {
        Display *dpy;
        Window wnd;
        std::string ttl;
        fwndptr ents;
        XEvent* ent;
        int w;
        int h;
    public:
        Wnd();
        void nextEvent();
        void events(fwndptr f);
        fwndptr events();
        void event(XEvent *e);
        XEvent* event();
        void show();
        void hide();
        std::string title();
        void title(const std::string& rename);
        Display* display();
        void display(Display* d);
        Window window();
        void window(Window w);
        int width();
        int height();
        bool isCorrect() { return (dpy != nullptr && wnd); }
    };
}

#endif // _LEARN_X11_WND_HPP_
