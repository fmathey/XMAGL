#ifndef _XMAGL_DISPLAY_HPP
#define _XMAGL_DISPLAY_HPP

#include <XMA/Engine.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Component;

// ---------------------------------------------------------------------------------------------------------------------

class Display
{
    friend class Component;

    public:

        virtual ~Display();

        Display& setBackgroundColor(float r, float g, float b);
        Display& setRelativeMouseMode(bool state = true);
        Display& setVerticalSync(bool state = true);

        glm::vec2 getSize() const;

        float getAspect() const;

    protected:

        Display(display_t& data);

    protected:

        display_t& m_data;
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
