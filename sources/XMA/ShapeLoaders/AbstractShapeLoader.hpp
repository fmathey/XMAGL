#ifndef _XMAGL_SHAPELOADERS_ABSTRACTSHAPELOADER_HPP
#define _XMAGL_SHAPELOADERS_ABSTRACTSHAPELOADER_HPP

#include <XMA/Shape.hpp>

namespace XMA {  namespace ShapeLoaders {

// ---------------------------------------------------------------------------------------------------------------------

class AbstractShapeLoader
{
    public:

        virtual ~AbstractShapeLoader() {}

        virtual Shape load(const std::string& filename) = 0;
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
