#include <XMA/Display.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Display::Display(display_t& data) : m_data(data)
{}

// ---------------------------------------------------------------------------------------------------------------------

Display::~Display()
{}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.f);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setRelativeMouseMode(bool state)
{
    SDL_SetRelativeMouseMode(state ? SDL_TRUE : SDL_FALSE);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setVerticalSync(bool state)
{
    SDL_GL_SetSwapInterval(state ? SDL_TRUE : SDL_FALSE);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Display::getSize() const
{
    int w, h;
    SDL_GetWindowSize(m_data.window, &w, &h);
    return glm::vec2((float) w, (float) h);
}

// ---------------------------------------------------------------------------------------------------------------------

float Display::getAspect() const
{
    glm::vec2 size { getSize() };
    return size.x / size.y;
}

// ---------------------------------------------------------------------------------------------------------------------

}