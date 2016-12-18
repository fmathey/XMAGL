#ifndef _XMAGL_TIMEOUT_HPP
#define _XMAGL_TIMEOUT_HPP

#include <XMA/Config.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Timeout
{
    public:

        Timeout();

        Timeout& reset();

        Timeout& update(std::function<void()> cb);

        Timeout& setInterval(Uint32 ms);

        Timeout& setRepeatable(bool state = true);
        Timeout& setIterations(Uint32 count);

    private:

        Uint32 m_interval { 0 };
        Uint32 m_nextTime { 0 };

        Uint32 m_iterations { 1 };
        Uint32 m_iteration { 0 };

        bool m_repeatable { false };
};

// ---------------------------------------------------------------------------------------------------------------------

typedef std::unique_ptr<Timeout> TimeoutUptr;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
