#include <XMA/Core/Shape.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

Shape::Shape()
{}

// ---------------------------------------------------------------------------------------------------------------------

Shape::Shape(const Shape& copy)
{
    vertices = copy.vertices;
    indices = copy.indices;
}

// ---------------------------------------------------------------------------------------------------------------------

Shape& Shape::transform(const glm::mat4& matrix)
{
    for(auto& v : vertices) {
        v.position = glm::vec3(matrix * glm::vec4(v.position, 1.f));
    }
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shape& Shape::transform(const Transform& t)
{
    return transform(t.getMatrix());
}

// ---------------------------------------------------------------------------------------------------------------------

Shape& Shape::merge(const Shape& shape)
{
    indices.clear();

    vertices.insert(vertices.end(), shape.vertices.begin(), shape.vertices.end());

    for(auto i(0u); i < vertices.size(); i++) {
        indices.push_back(i);
    }

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shape& Shape::merge(const std::vector<Shape>& shapes)
{
    indices.clear();

    for(auto& shape : shapes) {
        vertices.insert(vertices.end(), shape.vertices.begin(), shape.vertices.end());
    }

    for(auto i(0u); i < vertices.size(); i++) {
        indices.push_back(i);
    }

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

}}