#ifndef _XMAGL_CORE_DISPLAY_HPP
#define _XMAGL_CORE_DISPLAY_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Display
{
    XMA_PRIVATE_DATA();

    public:

        Display();

        virtual ~Display();

        Display& swap();
        Display& clear(GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Display& setBackgroundColor(float r, float g, float b);
        Display& setRelativeMouseMode(bool state = true);
        Display& setVerticalSync(bool state = true);

        glm::vec2 getSize() const;

        float getAspect() const;

};

// ---------------------------------------------------------------------------------------------------------------------

typedef std::unique_ptr<Display> DisplayUptr;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
