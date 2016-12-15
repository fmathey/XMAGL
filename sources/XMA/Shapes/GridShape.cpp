#include <XMA/Shapes/GridShape.hpp>

using namespace XMA::Core;

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

GridShape::GridShape(float size, Uint32 divisions, const glm::vec4& color)
{
    int   subdivisions = divisions;
    float offset{ -(size / 2) };
    float csize{ size / subdivisions };

    Uint32 incdice { 0 };

    for(auto i(0u); i < subdivisions + 1; ++i) {

        vertices.push_back(Vertex(glm::vec3(offset + (i * csize), 0.0f, offset), color));
        indices.push_back(incdice++);

        vertices.push_back(Vertex(glm::vec3(offset + (i * csize), 0.0f, offset + size), color));
        indices.push_back(incdice++);

        vertices.push_back(Vertex(glm::vec3(offset, 0.0f, offset + (i * csize)), color));
        indices.push_back(incdice++);

        vertices.push_back(Vertex(glm::vec3(offset + size, 0.0f, offset + (i * csize)), color));
        indices.push_back(incdice++);
    }
}

// ---------------------------------------------------------------------------------------------------------------------

}}