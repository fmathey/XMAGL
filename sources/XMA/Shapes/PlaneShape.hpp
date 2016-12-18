#ifndef _XMAGL_SHAPES_PLANESHAPE_HPP
#define _XMAGL_SHAPES_PLANESHAPE_HPP

#include <XMA/Shape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

struct PlaneShape : Shape
{
    PlaneShape(const glm::vec3& scale = glm::vec3(1.f), const glm::vec4& color = glm::vec4(1.f));
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
