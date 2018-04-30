#include <iostream>
#include <thread>
#include <chrono>
#include "../win/wsng.hpp"

bool isShow = false;

void btnpress(win::Wnd* w);
void leave(win::Wnd* w);

void btnpress(win::Wnd* w)
{
    win::Event* e = w->event();
    switch (e->msg) {
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        case WM_LBUTTONDOWN: {
            std::cout << "WM_LBUTTONDOWN" << std::endl;
            w->title("In WM_MOUSELEAVE mode");
            w->events(leave);
            break;
        }
    }
}

void leave(win::Wnd* w)
{
    if (!isShow) {
        isShow = true;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        w->show();
        return;
    }
    win::Event* e = w->event();
    switch (e->msg) {
        case WM_MOUSEMOVE: {
            TRACKMOUSEEVENT tme;
            tme.cbSize = sizeof(TRACKMOUSEEVENT);
            tme.dwFlags = TME_LEAVE;
            tme.dwHoverTime = 1;
            tme.hwndTrack = w->window();
            TrackMouseEvent(&tme);
            break;
        }
        case WM_MOUSELEAVE: {
            std::cout << "WM_MOUSELEAVE" << std::endl;
            w->title("In WM_LBUTTONDOWN mode");
            w->events(btnpress);
            break;
        }
    }
}

int main()
{
    win::Wnd* w = win::Wsng::create();
    w->events(leave);
    w->title("Titled");
    win::Wsng::run();
    return 0;
}
