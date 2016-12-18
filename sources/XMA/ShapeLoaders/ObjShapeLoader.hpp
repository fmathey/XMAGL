#ifndef _XMAGL_SHAPELOADERS_OBJSHAPELOADER_HPP
#define _XMAGL_SHAPELOADERS_OBJSHAPELOADER_HPP

#include <XMA/ShapeLoaders/AbstractShapeLoader.hpp>

namespace XMA {  namespace ShapeLoaders {

// ---------------------------------------------------------------------------------------------------------------------

class ObjShapeLoader
{
    public:

        ObjShapeLoader() {}

        virtual Shape load(const std::string& filename);
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
