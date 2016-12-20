#include <XMA/Components/GridComponent.hpp>
#include <XMA/Shapes/GridShape.hpp>

namespace XMA { namespace Components {

// ---------------------------------------------------------------------------------------------------------------------

GridComponent::GridComponent(float size)
        : m_size(size)
{}

// ---------------------------------------------------------------------------------------------------------------------

void GridComponent::create()
{

    m_buffer.addShape(Shapes::GridShape(m_size, m_size, glm::vec4(1.f, 1.f, 1.f, 0.2f)));

    m_buffer.generate();
}

// ---------------------------------------------------------------------------------------------------------------------

void GridComponent::render()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    m_shader.setTransform(getCamera().getMatrix());
    m_buffer.render(m_shader, 0, GL_LINES);

    glDisable(GL_BLEND);
}

// ---------------------------------------------------------------------------------------------------------------------

}}