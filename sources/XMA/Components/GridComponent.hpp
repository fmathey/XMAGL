#ifndef _XMAGL_COMPONENTS_GRIDCOMPONENT_HPP
#define _XMAGL_COMPONENTS_GRIDCOMPONENT_HPP

#include <XMA/Component.hpp>
#include <XMA/Entity.hpp>
#include <XMA/Shaders/GridShader.hpp>
#include <XMA/VertexBuffer.hpp>

namespace XMA { namespace Components {

// ---------------------------------------------------------------------------------------------------------------------

class GridComponent : public Component
{
    public:

        GridComponent(float size = 50.f);

        virtual void create() override;
        virtual void update(float deltaTime) override;

    private:

        VertexBuffer m_buffer;
        Shaders::GridShader m_shader;

        float m_size;
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
