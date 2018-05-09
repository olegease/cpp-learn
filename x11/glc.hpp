#ifndef _LEARN_X11_GLC_HPP_
#define _LEARN_X11_GLC_HPP_

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <array>


#include "wnd.hpp"

extern "C" {
    #include <X11/Xlib.h>
}

namespace x11
{
    class glc
    {
        std::array< GLint, 5 > att;
        GLXContext c;
    public:
        glc();
        GLXContext context();
        void context(GLXContext nc);
        GLint* attributes();
        void createWindow(Wnd& wnd);
    };
}

#endif // _LEARN_X11_GLC_HPP_
