#include <iostream>
#include <chrono>
#include <thread>
#include "../x11/wsng.hpp"

bool isShow = false;

void btnpress(x11::Wnd* w);
void leave(x11::Wnd* w);

void btnpress(x11::Wnd* w)
{
    XEvent* e = w->event();
    switch (e->type) {
        case ButtonPress: {
            std::cout << "ButtonPress" << std::endl;
            w->title("In LeaveNotify mode");
            w->events(leave);
            break;
        }
    }
}

void leave(x11::Wnd* w)
{
    XEvent* e = w->event();
    if (!isShow) {
        isShow = true;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        w->show();
        return;
    }
    switch (e->type) {
        case LeaveNotify: {
            std::cout << "LeaveNotify" << std::endl;
            w->title("In ButtonPress mode");
            w->events(btnpress);
            break;
        }
    }
}

int main()
{
    x11::Wnd mw(800, 1000);
    x11::Wnd* w = x11::Wsng::assign(mw);
    w->title("Titled");
    std::cout << w->title() << std::endl;
    w->events(leave);
    x11::Wsng::run();

    return 0;
}
