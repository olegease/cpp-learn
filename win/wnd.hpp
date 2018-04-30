#ifndef _LEARN_WIN_WND_HPP_
#define _LEARN_WIN_WND_HPP_

#include <string>

extern "C" {
    #include <windows.h>
}

namespace win
{
    struct Event
    {
        HWND wnd;
        unsigned int msg;
        WPARAM wp;
        LPARAM lp;
    };

    class Wnd;
    typedef void(*fwndptr)(Wnd*);

    class Wnd
    {
        HINSTANCE hin;
        HWND wnd;
        std::string ttl;
        fwndptr ents;
        Event* ent;
        int w;
        int h;
    public:
        Wnd();
        ~Wnd();
        bool isCorrect();
        void nextEvent();
        HWND window();
        void window(HWND w);
        Event* event();
        void event(Event* e);
        fwndptr events();
        void events(fwndptr f);
        void show();
        void hide();
        void title(const std::string& rename);
        std::string& title();
        int width();
        int height();
        void hinstance(HINSTANCE hInstance);
        HINSTANCE hinstance();
    };
}

#endif // _LEARN_WIN_WND_HPP_
