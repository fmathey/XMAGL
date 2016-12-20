#ifndef _XMAGL_COMPONENTS_GRIDCOMPONENT_HPP
#define _XMAGL_COMPONENTS_GRIDCOMPONENT_HPP

#include <XMA/Component.hpp>
#include <XMA/Entity.hpp>
#include <XMA/VertexBuffer.hpp>
#include <XMA/Shaders/FlatVertexColorShader.hpp>

namespace XMA { namespace Components {

// ---------------------------------------------------------------------------------------------------------------------

class GridComponent : public Component
{
    public:

        GridComponent(float size = 50.f);

        virtual void create() override;
        virtual void render() override;

    private:

        VertexBuffer m_buffer;
        Shaders::FlatVertexColorShader m_shader;

        float m_size;
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
