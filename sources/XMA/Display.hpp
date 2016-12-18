#ifndef _XMAGL_DISPLAY_HPP
#define _XMAGL_DISPLAY_HPP

#include <XMA/Config.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Engine;

// ---------------------------------------------------------------------------------------------------------------------

class Display
{
    friend class Engine;

    public:

        virtual ~Display();

        Display& setBackgroundColor(float r, float g, float b);
        Display& setRelativeMouseMode(bool state = true);
        Display& setVerticalSync(bool state = true);

        glm::vec2 getSize() const;

        float getAspect() const;

    protected:

        Display();

        Display& clear();
        Display& swap();

    protected:

        SDL_Window* m_window { nullptr };
        SDL_GLContext m_context { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

using DisplayUptr = std::unique_ptr<Display>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
