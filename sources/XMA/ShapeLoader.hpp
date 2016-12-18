#ifndef _XMAGL_SHAPELOADER_HPP
#define _XMAGL_SHAPELOADER_HPP

#include <XMA/Shape.hpp>

#include <XMA/ShapeLoaders/ObjShapeLoader.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

struct ShapeLoader
{
    static Shape OBJ(const std::string& filename) { return (ShapeLoaders::ObjShapeLoader()).load(filename); }
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
