#include <XMA/Display.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Display::Display()
{
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

    m_window = SDL_CreateWindow(
            "",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            0, 0,
            SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    XMA_ASSERT(m_window);

    m_context = SDL_GL_CreateContext(m_window);

    XMA_ASSERT(m_context);

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

    clear();
}

// ---------------------------------------------------------------------------------------------------------------------

Display::~Display()
{
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Display& Display::swap()
{
    SDL_GL_SwapWindow(m_window);
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
    SDL_GetWindowSize(m_window, &w, &h);
    return glm::vec2((float) w, (float) h);
}

// ---------------------------------------------------------------------------------------------------------------------

float Display::getAspect() const
{
    glm::vec2 size { getSize() };
    return size.x / size.y;
}

// ---------------------------------------------------------------------------------------------------------------------

}