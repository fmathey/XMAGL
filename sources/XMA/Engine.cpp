#include <XMA/Engine.hpp>
#include <XMA/Entity.hpp>
#include <XMA/Timer.hpp>
#include "Engine.hpp"

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

int Engine::run(std::function<void(Entity& entity)> callback)
{
    engine_t engine;

    try {

        XMA_ASSERT(SDL_Init(SDL_INIT_VIDEO) >= 0);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

        engine.display.window = SDL_CreateWindow(
                "",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                0, 0,
                SDL_WINDOW_FULLSCREEN_DESKTOP
        );

        XMA_ASSERT(engine.display.window);

        engine.display.context = SDL_GL_CreateContext(engine.display.window);

        XMA_ASSERT(engine.display.context);

#ifdef XMA_SYSTEM_MACOS
        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        XMA_ASSERT(GLEW_OK == err);
#endif

//        SDL_GL_SetSwapInterval(SDL_TRUE);
        SDL_GL_SetSwapInterval(SDL_FALSE);

        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_TEXTURE);
        glEnable(GL_TEXTURE_2D);
        glDepthFunc(GL_LESS);

        glClearColor(0.6f, 0.7f, 0.8f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);

        XMA_LOG()
        XMA_LOG("# ----------------------------------------")
        XMA_LOGKEY("OpenGL version", glGetString(GL_VERSION));
        XMA_LOGKEY("OpenGL shader version", glGetString(GL_SHADING_LANGUAGE_VERSION));
        XMA_LOG("# ----------------------------------------")
        XMA_LOG()

        Entity rootEntity(engine);

        engine.rootEntity = &rootEntity;

        callback(rootEntity);

        Timer timer;

        float frameTimeStart { 0 };
        float frameTimePrev { 0 };

        while(rootEntity.isAlive()) {

            frameTimeStart = timer.getSeconds();
            engine.deltaTime = (frameTimeStart - frameTimePrev) * engine.timeScale;
            frameTimePrev = frameTimeStart;

            SDL_Event e;

            engine.input.events.clear();

            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) rootEntity.destroy();
                else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) rootEntity.destroy();
                engine.input.events[e.type] = e;
            }

            engine.input.keyboardState = SDL_GetKeyboardState(NULL);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);

            rootEntity.update(engine.deltaTime);

            SDL_GL_SwapWindow(engine.display.window);

            engine.frameCount++;
            engine.elapsedTime = timer.getSeconds();
            engine.framesPerSeconds = engine.frameCount / engine.elapsedTime;
            engine.frameTime = engine.elapsedTime - frameTimeStart;
        }

        XMA_LOG()
        XMA_LOG("# ----------------------------------------")
        XMA_LOGKEY("Last FPS", engine.framesPerSeconds);
        XMA_LOGKEY("Last frame time", engine.frameTime);
        XMA_LOGKEY("Elapsed time", timer.getSeconds());
        XMA_LOG("# ----------------------------------------")
        XMA_LOG()

    } catch(const std::bad_alloc&) {
        std::cerr << "Erreur : mémoire insuffisante.\n";
    } catch(const std::out_of_range&) {
        std::cerr << "Erreur : débordement de mémoire.\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Oups ... :-(" << std::endl;
    }

    SDL_GL_DeleteContext(engine.display.context);
    SDL_DestroyWindow(engine.display.window);
    SDL_Quit();

    XMA_DUMP_LOG();

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

}