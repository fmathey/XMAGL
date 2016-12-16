#ifndef _XMAGL_CORE_VERTEXBUFFERDATA_HPP
#define _XMAGL_CORE_VERTEXBUFFERDATA_HPP

#include <XMA/Core/VertexBuffer.hpp>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct AbstractVertexBuffer::Data
{
    GLenum usage;

    GLuint vertexBufferID { 0 };
    GLuint indiceBufferID { 0 };

    GLsizeiptr vertexBufferSize { 0 };
    GLsizeiptr indiceBufferSize { 0 };

    std::vector<GLuint> vertexArrays;

    std::vector<Shape> shapes;

    std::vector<GLsizeiptr> shapeVerticesSizes;
    std::vector<GLsizeiptr> shapeIndicesSizes;
    std::vector<GLsizeiptr> shapeIndicesOffsets;

    Data(GLenum u = GL_STATIC_DRAW) : usage(u)
    {}

    ~Data()
    {
        glDeleteBuffers(1, &vertexBufferID);
        glDeleteBuffers(1, &indiceBufferID);

        for(auto i(0u); i < vertexArrays.size(); i++) {
            glDeleteVertexArrays(1, &vertexArrays[i]);
        }
    }

    void generateBuffers()
    {
        glGenBuffers(1, &vertexBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
        glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, 0, usage);

        glGenBuffers(1, &indiceBufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceBufferSize, 0, usage);

        Vertex vertex;

        GLsizeiptr vertexSize   = sizeof(vertex);
        GLsizeiptr positionSize = sizeof(vertex.position);
        GLsizeiptr texcoordSize = sizeof(vertex.texcoord);
        GLsizeiptr normalSize   = sizeof(vertex.normal);
        GLsizeiptr colorSize    = sizeof(vertex.color);

        GLsizeiptr verticesOffset { 0 };
        GLsizeiptr indicesOffset { 0 };

        for(auto i(0u); i < shapes.size(); i++) {

            GLsizeiptr verticesSize { shapeVerticesSizes[i] };
            GLsizeiptr indicesSize  { shapeIndicesSizes[i] };

            GLsizeiptr positionOffset { verticesOffset };
            GLsizeiptr texcoordOffset { positionOffset + positionSize };
            GLsizeiptr normalOffset   { texcoordOffset + texcoordSize };
            GLsizeiptr colorOffset    { normalOffset   + normalSize };

            glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
            glBufferSubData(GL_ARRAY_BUFFER, verticesOffset, verticesSize, &shapes[i].vertices[0]);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBufferID);
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, indicesOffset, indicesSize, &shapes[i].indices[0]);

            glGenVertexArrays(1, &vertexArrays[i]);
            glBindVertexArray(vertexArrays[i]);

            glEnableVertexAttribArray(0); // Positions
            glEnableVertexAttribArray(1); // Texcoords
            glEnableVertexAttribArray(2); // Normals
            glEnableVertexAttribArray(3); // Colors
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, BUFFER_OFFSET(positionOffset));
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, BUFFER_OFFSET(texcoordOffset));
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, vertexSize, BUFFER_OFFSET(normalOffset));
            glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, vertexSize, BUFFER_OFFSET(colorOffset));

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBufferID);

            shapeIndicesOffsets.push_back(indicesOffset);

            verticesOffset += verticesSize;
            indicesOffset  += indicesSize;
        }

        glBindVertexArray(0);
    }

    void render(Shader& shader, ShapeID shapeID, GLenum mode)
    {
        XMA_ASSERT(vertexArrays[shapeID] > 0);

        glBindVertexArray(vertexArrays[shapeID]);

        shader.activate();
        shader.validate();

        glDrawElements(
                mode,
                shapes[shapeID].indices.size(),
                GL_UNSIGNED_INT,
                BUFFER_OFFSET(shapeIndicesOffsets[shapeID])
        );

        glBindVertexArray(0);
    }

    void addShape(const Shape& shape)
    {
        XMA_ASSERT(shape.vertices.size() > 0);
        XMA_ASSERT(shape.vertices.size() == shape.indices.size());

        GLsizeiptr verticesSize = shape.vertices.size() * sizeof(shape.vertices[0]);
        GLsizeiptr indicesSize  = shape.indices.size()  * sizeof(shape.indices[0]);

        shapes.push_back(shape);
        shapeVerticesSizes.push_back(verticesSize);
        shapeIndicesSizes.push_back(indicesSize);
        vertexArrays.push_back(0);

        vertexBufferSize += verticesSize;
        indiceBufferSize += indicesSize;
    }

    void updateShape(ShapeID shapeID)
    {
        GLsizeiptr verticesSize = shapes[shapeID].vertices.size() * sizeof(shapes[shapeID].vertices[0]);
        GLsizeiptr indicesSize  = shapes[shapeID].indices.size()  * sizeof(shapes[shapeID].indices[0]);

        XMA_ASSERT(verticesSize == shapeVerticesSizes[shapeID]);
        XMA_ASSERT(indicesSize == shapeIndicesSizes[shapeID]);

        GLsizeiptr verticesOffset { shapeIndicesOffsets[shapeID] };

        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
        glBufferSubData(GL_ARRAY_BUFFER, verticesOffset, verticesSize, &shapes[shapeID].vertices[0]);
    }

};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
