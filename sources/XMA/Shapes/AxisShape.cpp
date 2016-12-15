#include <XMA/Shapes/AxisShape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

AxisShape::AxisShape(float size)
{
    // X - red

    vertices.push_back(Core::Vertex(
            glm::vec3(-1.f, 0.f, 0.f) * size,
            glm::vec4(1.f, 0.f, 0.f, 1.f)
    ));
    vertices.push_back(Core::Vertex(
            glm::vec3(1.f, 0.f, 0.f) * size,
            glm::vec4(1.f, 0.f, 0.f, 1.f)
    ));

    // Y - green

    vertices.push_back(Core::Vertex(
            glm::vec3(0.f, -1.f, 0.f) * size,
            glm::vec4(0.f, 1.f, 0.f, 1.f)
    ));
    vertices.push_back(Core::Vertex(
            glm::vec3(0.0f, 1.f, 0.f),
            glm::vec4(0.f, 1.f, 0.f, 1.f)
    ));

    // Z - blue

    vertices.push_back(Core::Vertex(
            glm::vec3(0.f, 0.f, -1.f) * size,
            glm::vec4(0.f, 0.f, 1.f, 1.f)
    ));
    vertices.push_back(Core::Vertex(
            glm::vec3(0.0f, 0.f, 1.f) * size,
            glm::vec4(0.f, 0.f, 1.f, 1.f)
    ));

    for(auto i(0u); i < vertices.size(); i++) {
        indices.push_back(i);
    }
}

// ---------------------------------------------------------------------------------------------------------------------

}}