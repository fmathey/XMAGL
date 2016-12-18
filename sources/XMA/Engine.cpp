#include <XMA/Engine.hpp>
#include <XMA/Entity.hpp>
#include <XMA/Timer.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Engine::Engine()
{}

// ---------------------------------------------------------------------------------------------------------------------

int Engine::run(std::function<void(Entity& entity)> callback)
{
    try {

        XMA_ASSERT(SDL_Init(SDL_INIT_EVERYTHING) >= 0);

        Engine engine;

        engine.camera
                .setPosition(glm::vec3(10, 35, -55))
                .setAspect(engine.display.getAspect());

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

            engine.input.update();

            if(engine.input.hasEvent(SDL_QUIT)) rootEntity.destroy();
            else if(engine.input.isKeyPressed(Key::ESCAPE)) rootEntity.destroy();

            engine.display.clear();

            rootEntity.update(engine.deltaTime);

            engine.display.swap();

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

    SDL_Quit();

    XMA_DUMP_LOG();

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

}