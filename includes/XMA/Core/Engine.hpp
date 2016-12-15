#ifndef _XMAGL_CORE_ENGINE_HPP
#define _XMAGL_CORE_ENGINE_HPP

#include <XMA/Core/Config.hpp>
#include <XMA/Core/Display.hpp>
#include <XMA/Core/Input.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class ControllerList;

// ---------------------------------------------------------------------------------------------------------------------

class Engine
{
    XMA_PRIVATE_DATA();

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

        glm::mat4 getCameraMatrix() const;
        glm::mat4 getWorldMatrix() const;
        glm::mat4 getViewProjection() const;

        Engine& setCameraMatrix(const glm::mat4& mat4);
        Engine& setWorldMatrix(const glm::mat4& mat4);

    private:

        Engine& update(float deltaTime);
        Engine& render();
        Engine& dispose();

        Engine& beginFrame();
        Engine& endFrame();

        Engine& processEvents();
};

// ---------------------------------------------------------------------------------------------------------------------

using EngineUptr = std::unique_ptr<Engine>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
