#ifndef _LEARN_X11_GLC_HPP_
#define _LEARN_X11_GLC_HPP_

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <array>

namespace x11
{
    class glc
    {
        std::array< GLint, 5 > att;
        GLXContext c;
    public:
        glc(): att({GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None}) { }
        GLXContext context() { return c; }
        void context(GLXContext nc) { c = nc; }
        GLint* attributes() { return &att[0]; }
    };
}

#endif // _LEARN_X11_GLC_HPP_
