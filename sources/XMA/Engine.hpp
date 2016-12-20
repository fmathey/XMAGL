#ifndef _XMAGL_ENGINE_HPP
#define _XMAGL_ENGINE_HPP

#include <XMA/Config.hpp>
#include <XMA/Camera.hpp>
#include <XMA/Display.hpp>
#include <XMA/Input.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Entity;
class Component;

// ---------------------------------------------------------------------------------------------------------------------

class Engine
{
    friend class Entity;
    friend class Component;

    public:

        static int run(std::function<void(Entity& entity)> callback);

    private:

        Engine();

        Camera camera;
        Display display;
        Input input;

        Uint64 frameCount { 0 };
        float elapsedTime { 0.f };
        float deltaTime { 0.f };
        float frameTime { 0.f };
        float framesPerSeconds { 0.f };
        float timeScale { 1.f };

        Entity* rootEntity { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
