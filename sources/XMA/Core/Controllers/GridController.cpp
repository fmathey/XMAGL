#include <XMA/Core/Controllers/GridController.hpp>
#include <XMA/Shapes/GridShape.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

GridController::GridController(float size, Uint32 divisions)
    : m_size(size), m_divisions(divisions)
{}

// ---------------------------------------------------------------------------------------------------------------------

void GridController::create()
{
    Shape grid = Shapes::GridShape(m_size, m_divisions, glm::vec4(1.f, 1.f, 1.f, 0.2f));

    m_buffer = StaticVertexBufferUptr(new StaticVertexBuffer(grid));
}

void GridController::render()
{
    m_shader.setTransform(getEngine().getViewProjection());

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    m_buffer->render(m_shader, 0, GL_LINES);

    glDisable(GL_BLEND);
}

// ---------------------------------------------------------------------------------------------------------------------

}}}