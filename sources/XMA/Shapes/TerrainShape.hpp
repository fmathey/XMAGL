#ifndef _XMAGL_SHAPES_TERRAINSHAPE_HPP
#define _XMAGL_SHAPES_TERRAINSHAPE_HPP

#include <XMA/Shape.hpp>

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

class TerrainShape : public Shape
{
    public:

        // @resolution must be a multiple of 8
        //
        // @size.y = Map height limit
        // If @size.x and @size.z == 0 then use (map size / resolution)
        //
        // @heigtmapFilename is an image used to get height
        // Width and height must be equal and multiple of 8
        //
        // @colormapFilename is an image used to get colors
        // Width and height must be equal and multiple of 8
        //
        TerrainShape(
                int resolution,
                const glm::vec3& size,
                const std::string& heigtmapFilename,
                const std::string& colormapFilename = ""
        );
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
