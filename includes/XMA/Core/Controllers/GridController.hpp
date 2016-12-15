#ifndef _XMAGL_CORE_CONTROLLERS_GRIDCONTROLLER_HPP
#define _XMAGL_CORE_CONTROLLERS_GRIDCONTROLLER_HPP

#include <XMA/Core/Controller.hpp>
#include <XMA/Core/Shaders/FlatVertexColorShader.hpp>
#include <XMA/Core/VertexBuffer.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

class GridController : public Controller
{
    public:

        GridController(float size = 60.f, Uint32 divisions = 60);

        virtual void create() override;

        virtual void render() override;

    private:

        StaticVertexBufferUptr m_buffer;

        Shaders::FlatVertexColorShader m_shader;

        float m_size;
        float m_divisions;
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
