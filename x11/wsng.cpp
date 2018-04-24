#include "wsng.hpp"

namespace x11
{
    Wnd Wsng::wnd = Wnd();

    Wsng::Wsng() { open(); }
    Wsng::~Wsng() { close(); }
    Wsng& Wsng::instance()
    {
        static Wsng sng;
        return sng;
    }

    void Wsng::open()
    {
        Display *dpy = XOpenDisplay(NULL);
        Wnd* w = Wsng::window();
        w->display(dpy);
        XSetWindowAttributes attr;
        Window wid = XCreateWindow(
            dpy,
            XRootWindow(dpy, 0),
            0, 0, w->width(), w->height(), 1,
            XDefaultDepth(dpy, 0),
            InputOutput,
            XDefaultVisual(dpy, 0),
            CWBackPixel,
            &attr
        );
        w->window(wid);
        XStoreName(dpy, wid, w->title().c_str());
        XSelectInput(dpy, wid, ExposureMask | ButtonPressMask | LeaveWindowMask);
    }

    void Wsng::close()
    {
        Wnd* wnd = Wsng::window();
        XDestroyWindow(wnd->display(), wnd->window());
        XCloseDisplay(wnd->display());
    }

    Wnd* Wsng::window()
    {
        return &Wsng::wnd;
    }

    Wnd* Wsng::create()
    {
        Wsng::instance();
        return &Wsng::wnd;
    }

    Wnd* Wsng::create(std::string rename)
    {
        Wsng::instance();
        Wsng::wnd.title(rename);
        return &Wsng::wnd;
    }

    void Wsng::run()
    {
        Wsng::instance();
        while (1) {
            Wsng::wnd.nextEvent();
        }
    }
}
