#ifndef _XMAGL_CORE_ENGINE_HPP
#define _XMAGL_CORE_ENGINE_HPP

#include <XMA/Core/Config.hpp>
#include <XMA/Core/Controller.hpp>
#include <XMA/Core/ControllerList.hpp>
#include <XMA/Core/Display.hpp>
#include <XMA/Core/Input.hpp>
#include <XMA/Core/Timer.hpp>

#include <XMA/Core/Controllers/SceneController.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Engine
{
    public:

        Engine();

        virtual ~Engine();

        Engine& run();

        ControllerList& getControllers();

        Display& getDisplay();
        Input& getInput();

        bool shouldContinue() const;
        Engine& shouldContinue(bool state);
        Engine& shouldQuitOnEscape(bool state);

        float getFramesPerSecond() const;
        float getFrameTime() const;
        float getDeltaTime() const;
        float getElapsedTime() const;
        float getTimeScale() const;

        Engine& setTimeScale(float scale);

    private:

        Engine& update(float deltaTime);
        Engine& render();
        Engine& dispose();

        Engine& beginFrame();
        Engine& endFrame();

        Engine& processEvents();

    private:

        bool m_shouldContinue { true };
        bool m_shouldQuitOnEscape { true };

        float m_timeScale { 1.f };
        float m_frameTime { 0.f };
        float m_deltaTime { 0.f };
        float m_framesPerSeconds { 0.f };

        float m_frameTimePrev { 0 };
        float m_frameTimeStart { 0 };

        Uint64 m_frameCount { 0 };

        Display m_display;
        Input m_input;
        Timer m_timer;

        ControllerListUptr m_controllers { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

typedef std::unique_ptr<Engine> EngineUptr;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
