#include "@EngineData.hpp"
#include "@InputData.hpp"

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

Engine::Engine()
{
    m_data = std::unique_ptr<Data>(new Data);

    m_data->controllers = ControllerListUptr(new ControllerList(*this));

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
    m_data->timer.reset();

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
    m_data->frameTimeStart = m_data->timer.getSeconds();
    m_data->deltaTime = (m_data->frameTimeStart - m_data->frameTimePrev) * m_data->timeScale;
    m_data->frameTimePrev = m_data->frameTimeStart;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::endFrame()
{
    float elapseTime = getElapsedTime();
    m_data->frameCount++;
    m_data->framesPerSeconds = m_data->frameCount / elapseTime;
    m_data->frameTime = elapseTime - m_data->frameTimeStart;
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
    return *m_data->controllers.get();
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Engine::getDisplay()
{
    return m_data->display;
}

// ---------------------------------------------------------------------------------------------------------------------

Input& Engine::getInput()
{
    return m_data->input;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::shouldContinue(bool state)
{
    m_data->shouldContinue = state;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::shouldQuitOnEscape(bool state)
{
    m_data->shouldQuitOnEscape = state;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

bool Engine::shouldContinue() const
{
    return m_data->shouldContinue;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getFramesPerSecond() const
{
    return m_data->framesPerSeconds;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getFrameTime() const
{
    return m_data->frameTime;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getDeltaTime() const
{
    return m_data->deltaTime;
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getElapsedTime() const
{
    return m_data->timer.getSeconds();
}

// ---------------------------------------------------------------------------------------------------------------------

float Engine::getTimeScale() const
{
    return m_data->timeScale;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::setTimeScale(float scale)
{
    m_data->timeScale = scale;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::processEvents()
{
    getInput().m_data->clearEvents();

    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) shouldContinue(false);
        else if(m_data->shouldQuitOnEscape && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) shouldContinue(false);
        getInput().m_data->pushEvent(e);
    }

    getInput().m_data->updateKeyboardState();
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::mat4 Engine::getCameraMatrix() const
{
    return m_data->cameraMatrix;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::mat4 Engine::getWorldMatrix() const
{
    return m_data->worldMatrix;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::mat4 Engine::getViewProjection() const
{
    return m_data->cameraMatrix * m_data->worldMatrix;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::setCameraMatrix(const glm::mat4& mat4)
{
    m_data->cameraMatrix = mat4;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Engine& Engine::setWorldMatrix(const glm::mat4& mat4)
{
    m_data->worldMatrix = mat4;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

}}