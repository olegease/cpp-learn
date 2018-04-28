#include "wsng.hpp"

namespace win
{
    Wnd Wsng::wnd = Wnd();
    Wsng::Wsng() { open(); }
    Wsng::~Wsng() { close(); }

    Wsng& Wsng::instance()
    {
        static Wsng sng;
        return sng;
    }

    long __stdcall Wsng::WindowProcedure(HWND hWnd, unsigned int msg, WPARAM wp, LPARAM lp)
    {
        Wnd* w = window();
        Event* e = w->event();
        e->wnd = hWnd;
        e->msg = msg;
        e->wp = wp;
        e->lp = lp;
        wnd.nextEvent();
        return DefWindowProc(hWnd, msg, wp, lp);
    }

    Wnd* Wsng::window() { return &wnd; }

    Wnd* Wsng::create()
    {
        instance();
        return &wnd;
    }

    void Wsng::run()
    {
        if (!wnd.isCorrect()) return;
        if (wnd.events() == nullptr) wnd.show();
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void Wsng::open()
    {
        const char* const myclass = "application";

        wnd.hinstance(GetModuleHandle(NULL));

        WNDCLASSEX c;
        c.cbSize = sizeof(WNDCLASSEX);
        c.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        c.lpfnWndProc = WindowProcedure;
        c.cbClsExtra = 0;
        c.cbWndExtra = 0;
        c.hInstance = wnd.hinstance();
        c.hIcon = NULL;
        c.hCursor = LoadCursor(0, IDC_ARROW);
        c.hbrBackground = HBRUSH(COLOR_WINDOW + 1);
        c.lpszMenuName = NULL;
        c.lpszClassName = myclass;
        c.hIconSm = NULL;// LoadIcon(0, IDI_APPLICATION);

        RegisterClassEx(&c);
        HWND wid = CreateWindowEx(
            0,
            myclass,
            wnd.title().c_str(),
            WS_OVERLAPPEDWINDOW,
            0,
            0,
            wnd.width(),
            wnd.height(),
            NULL,
            NULL,
            wnd.hinstance(),
            NULL
        );

        wnd.window(wid);
    }
    void Wsng::close() { }
}
