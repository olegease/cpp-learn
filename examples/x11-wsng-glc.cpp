#include "../x11/wsng.hpp"
#include "../x11/glc.hpp"
#include <iostream>

void f(x11::Wnd* w)
{
    XEvent* e = w->event();
    switch (e->type) {
        case Expose: {
            glViewport(0, 0, w->width(), w->height());
            glBegin(GL_TRIANGLES);
                glColor3f(1.f, 0.f, 0.f); glVertex3f(0.0f, 0.5f, 0.0f);
                glColor3f(0.f, 1.f, 0.f); glVertex3f(0.5f, -0.5f, 0.0f);
                glColor3f(0.f, 0.f, 1.f); glVertex3f(-0.5f, -0.5f, 0.0f);
            glEnd();
            glXSwapBuffers(w->display(), w->window());
            break;
        }
    }
}

int main()
{
    x11::Wnd win(200, 200);
    x11::glc glc;

    glc.createWindow(win);
    x11::Wnd* w = x11::Wsng::assign(win);
    w->title("OpenGL default context example, context version: ");
    w->events(f);
    glViewport(0, 0, w->width(), w->height());
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    w->show();
    x11::Wsng::run();

    return 0;
}
