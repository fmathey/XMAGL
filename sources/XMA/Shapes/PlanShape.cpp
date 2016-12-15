#include <XMA/Shapes/PlaneShape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

PlaneShape::PlaneShape(const glm::vec3& scale, const glm::vec4& color)
{
    vertices.push_back(Core::Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(1.000000, 1.000000),
            color
    ));
    indices.push_back(0);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(1);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 1.000000),
            color
    ));
    indices.push_back(2);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(1.000000, 1.000000),
            color
    ));
    indices.push_back(3);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(1.000000, 0.000000),
            color
    ));
    indices.push_back(4);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(5);
}

// ---------------------------------------------------------------------------------------------------------------------

}}