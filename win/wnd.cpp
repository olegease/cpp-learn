#include "wnd.hpp"

#include <iostream>

namespace win
{
    Wnd::Wnd() : w(640), h(480), ttl("Untitled"), ent(new Event), ents(nullptr), hin(0), wnd(0) { }
    Wnd::~Wnd() { delete ent; }

    bool Wnd::isCorrect() { return (hin && wnd); }

    void Wnd::nextEvent()
    {
        if (ents != nullptr) {
            ents(this);
        }
    }

    void Wnd::window(HWND window) { wnd = window; }
    HWND Wnd::window() { return wnd; }

    void Wnd::event(Event* event) { ent = event; }
    Event* Wnd::event() { return ent; }

    void Wnd::events(fwndptr events) { ents = events; }
    fwndptr Wnd::events() { return ents; }

    void Wnd::show() { if (isCorrect()) ShowWindow(wnd, SW_SHOW); }
    void Wnd::hide() { if (isCorrect()) ShowWindow(wnd, SW_HIDE); }

    void Wnd::title(const std::string& rename)
    {
        ttl = rename;
        if (isCorrect()) SetWindowText(wnd, rename.c_str());
    }
    std::string& Wnd::title() { return ttl; }

    int Wnd::width() { return w; }
    int Wnd::height() { return h; }

    HINSTANCE Wnd::hinstance() { return hin; }
    void Wnd::hinstance(HINSTANCE hInstance) { hin = hInstance; }
}
