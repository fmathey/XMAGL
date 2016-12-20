#ifndef _XMAGL_VERTEXBUFFER_HPP
#define _XMAGL_VERTEXBUFFER_HPP

#include <XMA/Shader.hpp>
#include <XMA/Shape.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

using ShapeID = Uint64;

class Engine;

// ---------------------------------------------------------------------------------------------------------------------

class VertexBuffer
{
    friend class Engine;

    XMA_PRIVATE_DATA();

    public:

        VertexBuffer();

        virtual ~VertexBuffer();

        ShapeID addShape(const Shape& shape);

        bool hasShapeID(ShapeID shapeID) const;

        Shape& getShape(ShapeID shapeID = 0);

        Uint64 getShapeCount() const;

        VertexBuffer& updateShape(ShapeID shapeID = 0);

        VertexBuffer& generate();

        VertexBuffer& render(Shader& shader, ShapeID shapeID = 0, GLenum mode = GL_TRIANGLES);


    private:

        static Uint32 nbDrawCalls;
};

// ---------------------------------------------------------------------------------------------------------------------

using VertexBufferUptr = std::unique_ptr<VertexBuffer>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
