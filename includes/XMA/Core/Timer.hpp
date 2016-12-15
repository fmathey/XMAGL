#ifndef _XMAGL_CORE_TIMER_HPP
#define _XMAGL_CORE_TIMER_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Timer
{
    public:

        Timer();

        virtual ~Timer();

        Timer* reset();

        float getSeconds() const;

    private:

        Uint64 m_start { 0 };
};

// ---------------------------------------------------------------------------------------------------------------------

using TimerUptr = std::unique_ptr<Timer>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
