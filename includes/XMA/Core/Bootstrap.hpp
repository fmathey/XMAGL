#ifndef _XMAGL_CORE_BOOTSTRAP_HPP
#define _XMAGL_CORE_BOOTSTRAP_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Bootstrap
{
    static int run(std::function<void()> callback);
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
