#include <XMA/Shapes/CubeShape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

CubeShape::CubeShape(const glm::vec3& scale, const glm::vec4& color)
{
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(0);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(1);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(2);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(3);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(4);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(-1.000000, 0.000000, 0.000000),
            glm::vec2(1.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(5);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(6);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(0.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(7);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(8);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(9);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(10);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 0.000000, -1.000000),
            glm::vec2(1.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(11);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(12);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(13);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(-1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(14);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(15);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(-1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(16);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(1.000000, 0.000000, 0.000000),
            glm::vec2(-1.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(17);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(18);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(0.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(19);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(-1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(20);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(0.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(21);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(-1.000000, -0.250000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(22);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 0.000000, 1.000000),
            glm::vec2(-1.000000, 0.750000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(23);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(0.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(24);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(1.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(25);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(1.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(26);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(0.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(27);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(1.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(28);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, -1.000000, 0.000000),
            glm::vec2(0.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(29);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(30);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(-1.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(31);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(-1.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(32);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 1.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(33);
    vertices.push_back(Vertex(
            glm::vec3(-0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(-1.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(34);
    vertices.push_back(Vertex(
            glm::vec3(0.500000, 1.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 2.000000),
            glm::vec4(0.800000, 0.800000, 0.800000, 0.000000)
    ));
    indices.push_back(35);
}

// ---------------------------------------------------------------------------------------------------------------------

}}