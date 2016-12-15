#ifndef _XMAGL_CORE_SHAPE_HPP
#define _XMAGL_CORE_SHAPE_HPP

#include <XMA/Core/Vertex.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Shape
{
    std::vector<Vertex> vertices;
    std::vector<Uint32> indices;
};

// ---------------------------------------------------------------------------------------------------------------------

using ShapeVector = std::vector<Shape>;

using ShapeUptr = std::unique_ptr<Shape>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
