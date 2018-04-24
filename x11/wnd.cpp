#include "wnd.hpp"

namespace x11
{
    Wnd::Wnd(): ttl("Untitled"), w(640), h(480), ents([=](Wnd*)->void {}) { }

    void Wnd::nextEvent()
    {
        if (ents != nullptr) {
            XEvent e;
            XNextEvent(dpy, reinterpret_cast< XEvent* >(&e));
            ent = &e;
            ents(this);
        }
    }

    void Wnd::events(fwndptr f) { ents = f; }

    fwndptr Wnd::events() { return ents; }

    void Wnd::event(XEvent *e) { ent = e; }

    XEvent* Wnd::event() { return ent; }

    void Wnd::show() { XMapWindow(dpy, wnd); }

    void Wnd::hide() { XUnmapWindow(dpy, wnd); }

    std::string Wnd::title() { return ttl; }

    void Wnd::title(std::string rename)
    {
        ttl = rename;
        if (dpy != nullptr) XStoreName(dpy, wnd, rename.c_str());
    }

    Display* Wnd::display() { return dpy; }

    void Wnd::display(Display* d) { dpy = d; }

    Window Wnd::window() { return wnd; }

    void Wnd::window(Window w) { wnd = w; }

    int Wnd::width() { return w; }

    int Wnd::height() { return h; }
}
