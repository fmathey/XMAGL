#ifndef _XMAGL_TIMER_HPP
#define _XMAGL_TIMER_HPP

#include <XMA/Config.hpp>

namespace XMA {

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

}

#endif
