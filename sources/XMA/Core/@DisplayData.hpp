#ifndef _XMAGL_CORE_DISPLAYDATA_HXX
#define _XMAGL_CORE_DISPLAYDATA_HXX

#include <XMA/Core/Display.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Display::Data
{
    SDL_Window* window{nullptr};
    SDL_GLContext context{nullptr};
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
