#ifndef _XMAGL_CORE_ENGINEDATA_HPP
#define _XMAGL_CORE_ENGINEDATA_HPP

#include <XMA/Core/Engine.hpp>
#include <XMA/Core/ControllerList.hpp>
#include <XMA/Core/Timer.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Engine::Data
{
    bool shouldContinue { true };
    bool shouldQuitOnEscape { true };

    float timeScale { 1.f };
    float frameTime { 0.f };
    float deltaTime { 0.f };
    float framesPerSeconds { 0.f };

    float frameTimePrev { 0 };
    float frameTimeStart { 0 };

    Uint64 frameCount { 0 };

    glm::mat4 cameraMatrix;
    glm::mat4 worldMatrix;

    Display display;
    Input input;
    Timer timer;

    ControllerListUptr controllers { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
