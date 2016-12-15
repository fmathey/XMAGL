#include <XMA/Core/Input.hpp>
#include "@InputData.hpp"

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

Input::Input()
{
    m_data = std::unique_ptr<Data>(new Data);

    m_data->updateKeyboardState();
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isKeyPressed(Key::Code key) const
{
    return m_data->keyboardState[SDL_GetScancodeFromKey(key)];
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonPressed(Mouse::Button button) const
{
    return (bool) (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button));
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonUp(Mouse::Button button) const
{
    return m_data->hasEvent(SDL_MOUSEBUTTONUP);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonDown(Mouse::Button button) const
{
    return m_data->hasEvent(SDL_MOUSEBUTTONDOWN);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseMove() const
{
    return m_data->hasEvent(SDL_MOUSEMOTION);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseScroll() const
{
    return m_data->hasEvent(SDL_MOUSEWHEEL);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMouseScroll() const
{
    glm::vec2 v;

    if(isMouseScroll()) {
        SDL_Event e = m_data->getEvent(SDL_MOUSEWHEEL);
        v.x = e.wheel.x;
        v.y = e.wheel.y;
    }

    return v;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMouseMove() const
{
    glm::vec2 v;

    if(isMouseMove()) {
        SDL_Event e = m_data->getEvent(SDL_MOUSEMOTION);
        v.x = e.motion.xrel;
        v.y = e.motion.yrel;
    }

    return v;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMousePosition() const
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return glm::vec2(x, y);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMousePositionRelative() const
{
    int x, y;
    SDL_GetRelativeMouseState(&x, &y);
    return glm::vec2(x, y);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMousePositionGlobal() const
{
    int x, y;
    SDL_GetGlobalMouseState(&x, &y);
    return glm::vec2(x, y);
}

// ---------------------------------------------------------------------------------------------------------------------

}}