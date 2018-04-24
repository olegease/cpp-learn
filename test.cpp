#include "x11/wsng.hpp"

void f2(x11::Wnd* w)
{
    static int counter = 0;
    counter++;
    switch (w->event()->type) {
        case Expose: {

        }
    }
}

void f(x11::Wnd* w)
{
    static int counter = 0;
    counter++;
    switch (w->event()->type) {
        case Expose: {
            w->events(f2);
            break;
        }
        case LeaveNotify: {
            break;
        }
    }
}

int main()
{
    x11::Wnd* w = x11::Wsng::create();
    w->show();
    w->events(f);

    x11::Wsng::run();




    return 0;
}
