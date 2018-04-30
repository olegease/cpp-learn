#include "wnd.hpp"

#include <iostream>

namespace x11
{
    Wnd::Wnd(): ttl("Untitled"), w(640), h(480), ents(nullptr), dpy(nullptr), wnd(0) { }

    void Wnd::nextEvent()
    {
        if (ents != nullptr) {
            ents(this);
        }
    }

    void Wnd::events(func_wnd f) { ents = f; }

    func_wnd Wnd::events() { return ents; }

    void Wnd::event(XEvent *e) { ent = e; }

    XEvent* Wnd::event() { return ent; }

    void Wnd::show() { if (isCorrect()) XMapWindow(dpy, wnd); }

    void Wnd::hide() { if (isCorrect()) XUnmapWindow(dpy, wnd); }

    std::string Wnd::title() { return ttl; }

    void Wnd::title(const std::string& rename)
    {
        ttl = rename;
        if (isCorrect()) XStoreName(dpy, wnd, rename.c_str());
    }

    Display* Wnd::display() { return dpy; }

    void Wnd::display(Display* d) { dpy = d; }

    Window Wnd::window() { return wnd; }

    void Wnd::window(Window w) { wnd = w; }

    int Wnd::width() { return w; }

    int Wnd::height() { return h; }
}
