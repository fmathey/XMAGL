#ifndef _XMAGL_VERTEX_HPP
#define _XMAGL_VERTEX_HPP

#include <XMA/Config.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

struct Vertex
{
    glm::vec3 position;
    glm::vec2 texcoord;
    glm::vec3 normal;
    glm::vec4 color;

    Vertex() : color(glm::vec4(1.f))
    {}

    Vertex(
            const glm::vec3& p,
            const glm::vec4& c = glm::vec4(1.f)
    )
            : position(p), color(c), normal(glm::vec3(0.f, 1.f, 0.f))
    {}

    Vertex(
            const glm::vec3& p,
            const glm::vec3& n,
            const glm::vec4& c
    )
            : position(p), normal(n), color(glm::vec4(1.f))
    {}

    Vertex(
            const glm::vec3& p,
            const glm::vec3& n,
            const glm::vec2& t
    )
            : position(p), normal(n), texcoord(t), color(glm::vec4(1.f))
    {}

    Vertex(
            const glm::vec3& p,
            const glm::vec3& n,
            const glm::vec2& t,
            const glm::vec4& c
    )
            : position(p), normal(n), texcoord(t), color(c)
    {}

    Vertex(
            const glm::vec3& p,
            const glm::vec3& n,
            const glm::vec4& c,
            const glm::vec2& t
    )
            : position(p), normal(n), texcoord(t), color(c)
    {}


};

// ---------------------------------------------------------------------------------------------------------------------

using VertexUptr = std::unique_ptr<Vertex>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
