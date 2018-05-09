#include "glc.hpp"

namespace x11
{
    glc::glc() : att({GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None}) { }

    GLXContext glc::context() { return c; }

    void glc::context(GLXContext nc) { c = nc; }

    GLint* glc::attributes() { return &att[0]; }

    void glc::createWindow(Wnd& wnd)
    {
        wnd.display(XOpenDisplay(NULL));
        Window root = XRootWindow(wnd.display(), 0);
        XSetWindowAttributes swa;
        swa.event_mask = ButtonPressMask | LeaveWindowMask | ExposureMask;
        XVisualInfo *vi = glXChooseVisual(wnd.display(), 0, attributes());
        Colormap cmap = XCreateColormap(wnd.display(), root, vi->visual, AllocNone);
        swa.colormap = cmap;
        wnd.window(XCreateWindow(
            wnd.display(),
            root,
            0, 0, wnd.width(), wnd.height(), 1,
            vi->depth,
            InputOutput,
            vi->visual,
            CWEventMask | CWColormap,
            &swa));
        context(glXCreateContext(
            wnd.display(),
            vi,
            NULL,
            GL_TRUE));
        glXMakeCurrent(wnd.display(), wnd.window(), context());
    }
}
