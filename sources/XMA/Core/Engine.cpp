#include <XMA/Core/Engine.hpp>
#include "@InputData.hpp"

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

Engine::Engine()
{
    m_controllers = ControllerListUptr(new ControllerList(*this));

    XMA_LOG("# -----------------------------------");
    XMA_LOGKEY("OpenGL version", glGetString(GL_VERSION));
    XMA_LOGKEY("OpenGL shader version", glGetString(GL_SHADING_LANGUAGE_VERSION));
    XMA_LOG("# -----------------------------------\n");
}

// ---------------------------------------------------------------------------------------------------------------------

Engine::~Engine()
{
    XMA_LOG("\n# --------------------------");
    XMA_LOGKEY("Last frames per second", (int) getFramesPerSecond());
    XMA_LOGKEY("Last frame time", getFrameTime());
    XMA_LOGKEY("Elapsed time", getElapsedTime());
    XMA_LOG("# --------------------------");
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::run()
{
    m_timer.reset();

    while(shouldContinue()) {
        beginFrame();
        processEvents();
        update(getDeltaTime());
        render();
        endFrame();
    }

    dispose();

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::beginFrame()
{
    m_frameTimeStart = m_timer.getSeconds();
    m_deltaTime = (m_frameTimeStart - m_frameTimePrev) * m_timeScale;
    m_frameTimePrev = m_frameTimeStart;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::endFrame()
{
    float elapseTime = getElapsedTime();
    m_frameCount++;
    m_framesPerSeconds = m_frameCount / elapseTime;
    m_frameTime = elapseTime - m_frameTimeStart;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::update(float deltaTime)
{
    getControllers().update(deltaTime);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::render()
{
    getDisplay().clear();
    getControllers().render();
    getDisplay().swap();
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::dispose()
{
    getControllers().dispose();
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

ControllerList& Engine::getControllers()
{
    return *m_controllers.get();
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Engine::getDisplay()
{
    return m_display;
}

// ---------------------------------------------------------------------------------------------------------------------

Input& Engine::getInput()
{
    return m_input;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::shouldContinue(bool state)
{
    m_shouldContinue = state;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::shouldQuitOnEscape(bool state)
{
    m_shouldQuitOnEscape = state;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

bool Engine::shouldContinue() const
{
    return m_shouldContinue;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getFramesPerSecond() const
{
    return m_framesPerSeconds;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getFrameTime() const
{
    return m_frameTime;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getDeltaTime() const
{
    return m_deltaTime;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getElapsedTime() const
{
    return m_timer.getSeconds();
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getTimeScale() const
{
    return m_timeScale;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::setTimeScale(float scale)
{
    m_timeScale = scale;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::processEvents()
{
    getInput().m_data->clearEvents();

    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) shouldContinue(false);
        else if(m_shouldQuitOnEscape && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) shouldContinue(false);
        getInput().m_data->pushEvent(e);
    }

    getInput().m_data->updateKeyboardState();
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

}}