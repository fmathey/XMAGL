#ifndef _XMAGL_VERTEXBUFFER_HPP
#define _XMAGL_VERTEXBUFFER_HPP

#include <XMA/Shader.hpp>
#include <XMA/Shape.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

using ShapeID = Uint64;

// ---------------------------------------------------------------------------------------------------------------------

class AbstractVertexBuffer
{
    XMA_PRIVATE_DATA();

    public:

        virtual ~AbstractVertexBuffer();

        AbstractVertexBuffer& render(Shader& shader, ShapeID shapeID = 0, GLenum mode = GL_TRIANGLES);

        bool hasShapeID(ShapeID shapeID) const;

        Uint64 getShapeCount() const;

    protected:

        AbstractVertexBuffer(const Shape& shape, GLenum usage = GL_STATIC_DRAW);
        AbstractVertexBuffer(const ShapeVector& shapes, GLenum usage = GL_STATIC_DRAW);

        Shape& getShape(ShapeID shapeID = 0);

        AbstractVertexBuffer& updateShape(ShapeID shapeID = 0);
};

// ---------------------------------------------------------------------------------------------------------------------

class StaticVertexBuffer : public AbstractVertexBuffer
{
    public:

        StaticVertexBuffer(const Shape& shape);
        StaticVertexBuffer(const ShapeVector& shapes);
};

// ---------------------------------------------------------------------------------------------------------------------

class DynamicVertexBuffer : public AbstractVertexBuffer
{
    public:

        DynamicVertexBuffer(const Shape& shape);
        DynamicVertexBuffer(const ShapeVector& shapes);

        using AbstractVertexBuffer::render;
        using AbstractVertexBuffer::updateShape;
        using AbstractVertexBuffer::getShape;
};

// ---------------------------------------------------------------------------------------------------------------------

using AbstractVertexBufferUptr = std::unique_ptr<AbstractVertexBuffer>;
using StaticVertexBufferUptr = std::unique_ptr<StaticVertexBuffer>;
using DynamicVertexBufferUptr = std::unique_ptr<DynamicVertexBuffer>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
