#ifndef _XMAGL_CORE_SHAPELOADERS_OBJSHAPELOADER_HPP
#define _XMAGL_CORE_SHAPELOADERS_OBJSHAPELOADER_HPP

#include <XMA/Core/ShapeLoaders/AbstractShapeLoader.hpp>

namespace XMA { namespace Core { namespace ShapeLoaders {

// ---------------------------------------------------------------------------------------------------------------------

class ObjShapeLoader
{
    public:

        ObjShapeLoader() {}

        virtual Shape load(const std::string& filename);
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
