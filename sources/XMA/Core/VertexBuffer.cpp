#include "@VertexBufferData.hpp"

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

AbstractVertexBuffer::AbstractVertexBuffer(const Shape& shape, GLenum usage)
{
    m_data = std::unique_ptr<Data>(new Data(usage));

    m_data->addShape(shape);

    m_data->generateBuffers();
}

// ---------------------------------------------------------------------------------------------------------------------

AbstractVertexBuffer::AbstractVertexBuffer(const ShapeVector& shapes, GLenum usage)
{
    m_data = std::unique_ptr<Data>(new Data(usage));

    for(auto& shape : shapes) {
        m_data->addShape(shape);
    }

    m_data->generateBuffers();
}

// ---------------------------------------------------------------------------------------------------------------------

AbstractVertexBuffer::~AbstractVertexBuffer()
{

}

// ---------------------------------------------------------------------------------------------------------------------

AbstractVertexBuffer& AbstractVertexBuffer::render(Shader& shader, ShapeID shapeID, GLenum mode)
{
    XMA_ASSERT(hasShapeID(shapeID));

    m_data->render(shader, shapeID, mode);

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

bool AbstractVertexBuffer::hasShapeID(ShapeID shapeID) const
{
    return shapeID < getShapeCount();
}

// ---------------------------------------------------------------------------------------------------------------------

Shape& AbstractVertexBuffer::getShape(ShapeID shapeID)
{
    XMA_ASSERT(hasShapeID(shapeID));
    return m_data->shapes[shapeID];
}

// ---------------------------------------------------------------------------------------------------------------------

AbstractVertexBuffer& AbstractVertexBuffer::updateShape(ShapeID shapeID)
{
    XMA_ASSERT(hasShapeID(shapeID));
    m_data->updateShape(shapeID);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Uint64 AbstractVertexBuffer::getShapeCount() const
{
    return m_data->shapes.size();
}

// ---------------------------------------------------------------------------------------------------------------------

StaticVertexBuffer::StaticVertexBuffer(const Shape& shape) : AbstractVertexBuffer(shape, GL_STATIC_DRAW)
{}

// ---------------------------------------------------------------------------------------------------------------------

DynamicVertexBuffer::DynamicVertexBuffer(const Shape& shape) : AbstractVertexBuffer(shape, GL_DYNAMIC_DRAW)
{}

// ---------------------------------------------------------------------------------------------------------------------

}}