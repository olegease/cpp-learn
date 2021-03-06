#include "wsng.hpp"

#include <iostream>

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
        if (wnd.isCorrect()) return;
        wnd.display(XOpenDisplay(NULL));
        Window root = XRootWindow(wnd.display(), 0);
        XSetWindowAttributes swa;
        swa.event_mask = ButtonPressMask | LeaveWindowMask | ExposureMask;
        int wmask = CWEventMask;
        int depth;
        Visual *visual;

        depth = XDefaultDepth(wnd.display(), 0);
        visual = XDefaultVisual(wnd.display(), 0);
        wmask |= CWBackPixel;

        wnd.window(XCreateWindow(
            wnd.display(),
            root,
            0, 0, wnd.width(), wnd.height(), 1,
            depth,
            InputOutput,
            visual,
            wmask,
            &swa
        ));
    }

    void Wsng::close()
    {
        Wnd* wnd = window();
        XDestroyWindow(wnd->display(), wnd->window());
        XCloseDisplay(wnd->display());
    }

    Wnd* Wsng::window()
    {
        return &wnd;
    }

    Wnd* Wsng::create()
    {
        instance();
        return &wnd;
    }

    Wnd* Wsng::create(std::string rename)
    {
        instance();
        wnd.title(rename);
        return &Wsng::wnd;
    }

    Wnd* Wsng::assign(const Wnd& rhs)
    {
        wnd = rhs;
        instance();
        return &wnd;
    }

    void Wsng::run()
    {
        // TODO: add exception
        if (!wnd.isCorrect()) return;
        // Show window as user cannot show it themself if it unmapped/hide
        if (wnd.events() == nullptr) wnd.show();

        Atom WM_DELETE_WINDOW = XInternAtom(wnd.display(), "WM_DELETE_WINDOW", false);
        XSetWMProtocols(wnd.display(), wnd.window(), &WM_DELETE_WINDOW, 1);

        XEvent e;
        while (1) {
            wnd.event(&e);
            // NOTE: first call user events function pointer
            // in case when user want define when to show window
            // in other order XNextEvent freezing application
            wnd.nextEvent();
            switch (e.type) {
                case ClientMessage: if (static_cast< Atom >(e.xclient.data.l[0]) == WM_DELETE_WINDOW) return;
            }
            XNextEvent(wnd.display(), static_cast< XEvent* >(&e));
        }
    }
}
