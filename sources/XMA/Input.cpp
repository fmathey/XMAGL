#include <XMA/Input.hpp>
#include <XMA/Engine.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Input::Input()
{

}

// ---------------------------------------------------------------------------------------------------------------------

Input& Input::update()
{
    SDL_Event e;

    m_events.clear();

    while(SDL_PollEvent(&e)) m_events[e.type] = e;

    m_keyboardState = SDL_GetKeyboardState(NULL);
    
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isKeyPressed(Key::Code key) const
{
    return m_keyboardState[SDL_GetScancodeFromKey(key)];
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonPressed(Mouse::Button button) const
{
    return (bool) (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button));
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonUp(Mouse::Button button) const
{
    return hasEvent(SDL_MOUSEBUTTONUP);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseButtonDown(Mouse::Button button) const
{
    return hasEvent(SDL_MOUSEBUTTONDOWN);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseMove() const
{
    return hasEvent(SDL_MOUSEMOTION);
}

// ---------------------------------------------------------------------------------------------------------------------

bool Input::isMouseScroll() const
{
    return hasEvent(SDL_MOUSEWHEEL);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Input::getMouseScroll() const
{
    glm::vec2 v;

    if(isMouseScroll()) {
        SDL_Event e = getEvent(SDL_MOUSEWHEEL);
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
        SDL_Event e = getEvent(SDL_MOUSEMOTION);
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

bool Input::hasEvent(Uint32 type) const
{
    return m_events.count(type) > 0;
}

// ---------------------------------------------------------------------------------------------------------------------

SDL_Event Input::getEvent(Uint32 type) const
{
    XMA_ASSERT(hasEvent(type));
    return m_events.at(type);
}

// ---------------------------------------------------------------------------------------------------------------------

}