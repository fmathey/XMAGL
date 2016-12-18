#ifndef _XMAGL_SHAPE_HPP
#define _XMAGL_SHAPE_HPP

#include <XMA/Vertex.hpp>
#include <XMA/Transform.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Shape
{
    public:

        std::vector<Vertex> vertices;
        std::vector<Uint32> indices;

    public:

        Shape();
        Shape(const Shape& copy);

        Shape& transform(const glm::mat4& matrix);
        Shape& transform(const Transform& transform);

        Shape& merge(const Shape& shape);
        Shape& merge(const std::vector<Shape>& shapes);
};

// ---------------------------------------------------------------------------------------------------------------------

using ShapeVector = std::vector<Shape>;

using ShapeUptr = std::unique_ptr<Shape>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
