#ifndef _XMAGL_ENGINE_HPP
#define _XMAGL_ENGINE_HPP

#include <XMA/Config.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Entity;

// ---------------------------------------------------------------------------------------------------------------------

typedef struct
{
    SDL_Window* window { nullptr };
    SDL_GLContext context{nullptr};

} display_t;

// ---------------------------------------------------------------------------------------------------------------------

typedef struct
{
    const Uint8* keyboardState { nullptr };

    std::map<Uint32, SDL_Event> events;

} input_t;

// ---------------------------------------------------------------------------------------------------------------------

typedef struct
{
    display_t display;
    input_t input;

    Uint64 frameCount { 0 };
    float elapsedTime { 0.f };
    float deltaTime { 0.f };
    float frameTime { 0.f };
    float framesPerSeconds { 0.f };
    float timeScale { 1.f };

    Entity* rootEntity { nullptr };

} engine_t;

// ---------------------------------------------------------------------------------------------------------------------

struct Engine
{
    static int run(std::function<void(Entity& entity)> callback);
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
