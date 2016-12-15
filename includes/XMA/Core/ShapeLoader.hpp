#ifndef _XMAGL_CORE_SHAPELOADER_HPP
#define _XMAGL_CORE_SHAPELOADER_HPP

#include <XMA/Core/Shape.hpp>

#include <XMA/Core/ShapeLoaders/ObjShapeLoader.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct ShapeLoader
{
    static Shape OBJ(const std::string& filename) { return (ShapeLoaders::ObjShapeLoader()).load(filename); }
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
