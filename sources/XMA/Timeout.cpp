#include <XMA/Timeout.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Timeout::Timeout()
{
    reset();
}

// ---------------------------------------------------------------------------------------------------------------------

Timeout& Timeout::setInterval(Uint32 ms)
{
    m_interval = ms;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Timeout& Timeout::setRepeatable(bool state)
{
    m_repeatable = state;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Timeout& Timeout::setIterations(Uint32 count)
{
    m_repeatable = false;
    m_iteration = 0;
    m_iterations = count;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Timeout& Timeout::reset()
{
    m_nextTime = SDL_GetTicks() + m_interval;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Timeout& Timeout::update(std::function<void()> cb)
{
    unsigned int time = SDL_GetTicks();

    if(m_repeatable) {
        if(time > m_nextTime + m_interval) {
            cb();
            reset();
        }
    } else if(m_iteration < m_iterations) {

        if(time > m_nextTime + m_interval) {
            cb();
            reset();
            m_iteration++;
        }

    }

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

}