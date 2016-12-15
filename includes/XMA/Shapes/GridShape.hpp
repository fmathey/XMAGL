#ifndef _XMAGL_SHAPES_GRIDSHAPE_HPP
#define _XMAGL_SHAPES_GRIDSHAPE_HPP

#include <XMA/Core/Shape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

struct GridShape : Core::Shape
{
    GridShape(float size = 60.f, Uint32 divisions = 60, const glm::vec4& color = glm::vec4(1.f));
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
