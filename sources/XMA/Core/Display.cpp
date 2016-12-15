#include <XMA/Core/Display.hpp>
#include "@DisplayData.hpp"

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

Display::Display()
{
    m_data = std::unique_ptr<Data>(new Data);

    XMA_ASSERT(SDL_Init(SDL_INIT_VIDEO) >= 0)

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

    m_data->window = SDL_CreateWindow(
            "",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            0, 0,
            SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    XMA_ASSERT(m_data->window);

    m_data->context = SDL_GL_CreateContext(m_data->window);

    XMA_ASSERT(m_data->context);

#ifdef __APPLE__
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    XMA_ASSERT(GLEW_OK == err);
#endif

    SDL_GL_SetSwapInterval(SDL_TRUE);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glDepthFunc(GL_LESS);

    setBackgroundColor(0.6f, 0.7f, 0.8f);
}

// ---------------------------------------------------------------------------------------------------------------------

Display::~Display()
{
    SDL_GL_DeleteContext(m_data->context);
    SDL_DestroyWindow(m_data->window);
    SDL_Quit();
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::swap()
{
    SDL_GL_SwapWindow(m_data->window);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::clear(GLbitfield mask)
{
    glClear(mask);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.f);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setRelativeMouseMode(bool state)
{
    SDL_SetRelativeMouseMode(state ? SDL_TRUE : SDL_FALSE);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::setVerticalSync(bool state)
{
    SDL_GL_SetSwapInterval(state ? SDL_TRUE : SDL_FALSE);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Display::getSize() const
{
    int w, h;
    SDL_GetWindowSize(m_data->window, &w, &h);
    return glm::vec2((float) w, (float) h);
}

// ---------------------------------------------------------------------------------------------------------------------

float Display::getAspect() const
{
    glm::vec2 size { getSize() };
    return size.x / size.y;
}

// ---------------------------------------------------------------------------------------------------------------------

}}