#ifndef _XMAGL_CORE_INPUTDATA_HXX
#define _XMAGL_CORE_INPUTDATA_HXX

#include <XMA/Core/Input.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Input::Data
{
    std::map<Uint32, SDL_Event> events;

    const Uint8 * keyboardState { nullptr };

    SDL_Event* event;

    void updateKeyboardState()
    { keyboardState = SDL_GetKeyboardState(NULL); }

    void pushEvent(const SDL_Event& e)
    { events[e.type] = e; }

    void clearEvents()
    { events.clear(); }

    bool hasEvent(Uint32 type) const
    { return events.count(type) > 0; }

    SDL_Event getEvent(Uint32 type) const
    {
        XMA_ASSERT(hasEvent(type));
        return events.at(type);
    }
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
