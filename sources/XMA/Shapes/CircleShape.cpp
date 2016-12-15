#include <XMA/Shapes/CircleShape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

CircleShape::CircleShape(const glm::vec3& scale, const glm::vec4& color)
{
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(0);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(1);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(2);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(3);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.000000, 0.000000, -0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(4);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097544, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(5);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097544, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(6);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.191341, 0.000000, -0.461940) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(7);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(8);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(9);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.353553, 0.000000, -0.353554) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(10);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(11);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415734, 0.000000, -0.277786) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(12);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.461940, 0.000000, -0.191342) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(13);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(14);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(15);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.500000, 0.000000, -0.000000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(16);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(17);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(18);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.461940, 0.000000, 0.191341) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(19);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(20);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(21);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.353554, 0.000000, 0.353553) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(22);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(23);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(24);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.191342, 0.000000, 0.461940) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(25);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(26);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(27);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.000000, 0.000000, 0.500000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(28);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(29);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(30);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.191342, 0.000000, 0.461940) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(31);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(32);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(33);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.353553, 0.000000, 0.353553) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(34);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(35);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(36);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.461940, 0.000000, 0.191342) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(37);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(38);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(39);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.500000, 0.000000, -0.000000) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(40);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, -0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(41);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, -0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(42);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.461940, 0.000000, -0.191342) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(43);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, -0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(44);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, -0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(45);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.353553, 0.000000, -0.353553) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(46);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(47);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(48);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.191342, 0.000000, -0.461940) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(49);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(50);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(51);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097544, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(52);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(53);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.353553, 0.000000, -0.353554) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(54);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415734, 0.000000, -0.277786) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(55);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(56);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(57);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(58);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(59);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(60);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.191342, 0.000000, 0.461940) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(61);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(62);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(63);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(64);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(65);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(66);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.461940, 0.000000, 0.191342) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(67);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(68);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(69);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, -0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(70);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, -0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(71);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, -0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(72);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(73);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(74);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(75);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.277785, 0.000000, -0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(76);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(77);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(78);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.415735, 0.000000, 0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(79);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(80);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(81);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.277785, 0.000000, 0.415735) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(82);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(83);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.490393, 0.000000, 0.097545) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(84);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.415735, 0.000000, -0.277785) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(85);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(86);
    vertices.push_back(Core::Vertex(
            glm::vec3(0.097545, 0.000000, -0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(87);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.490393, 0.000000, -0.097546) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(88);
    vertices.push_back(Core::Vertex(
            glm::vec3(-0.097545, 0.000000, 0.490393) * scale,
            glm::vec3(0.000000, 1.000000, 0.000000),
            glm::vec2(0.000000, 0.000000),
            color
    ));
    indices.push_back(89);
}

// ---------------------------------------------------------------------------------------------------------------------

}}