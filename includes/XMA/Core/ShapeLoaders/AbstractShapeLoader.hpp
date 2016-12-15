#ifndef _XMAGL_CORE_SHAPELOADERS_ABSTRACTSHAPELOADER_HPP
#define _XMAGL_CORE_SHAPELOADERS_ABSTRACTSHAPELOADER_HPP

#include <XMA/Core/Shape.hpp>

namespace XMA { namespace Core { namespace ShapeLoaders {

// ---------------------------------------------------------------------------------------------------------------------

class AbstractShapeLoader
{
    public:

        virtual ~AbstractShapeLoader() {}

        virtual Shape load(const std::string& filename) = 0;
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
