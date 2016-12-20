#include <XMA/ShapeLoaders/ObjShapeLoader.hpp>

#include <tiny_obj_loader.h>

namespace XMA {  namespace ShapeLoaders {

// ---------------------------------------------------------------------------------------------------------------------

Shape ObjShapeLoader::load(const std::string& filename)
{
    Shape outputShape;

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string err;

    std::string basePath;

    auto pos = filename.rfind('/');

    if (pos != std::string::npos) {
        basePath = filename;
        basePath.erase(pos);
        basePath += "/";
    }

    if(!tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename.c_str(), basePath.c_str(), true)) {
        throw std::runtime_error(err.c_str());
    }

    for (const auto& shape : shapes) {

        size_t index_offset = 0;

        for(auto f(0u); f < shape.mesh.num_face_vertices.size(); f++) {

            int fv = shape.mesh.num_face_vertices[f];

            auto materialID = shape.mesh.material_ids[f];

            glm::vec4 color;

            if(materials.size() && materialID < materials.size()) {
                color.r = materials[materialID].diffuse[0];
                color.g = materials[materialID].diffuse[1];
                color.b = materials[materialID].diffuse[2];
            }

            for (size_t v = 0; v < fv; v++) {

                tinyobj::index_t index = shape.mesh.indices[index_offset + v];

                Vertex vertex;

                vertex.position = glm::vec3(
                        attrib.vertices[3 * index.vertex_index + 0],
                        attrib.vertices[3 * index.vertex_index + 1],
                        attrib.vertices[3 * index.vertex_index + 2]
                );

                if(attrib.texcoords.size()) {
                    vertex.texcoord = glm::vec2(
                            attrib.texcoords[2 * index.texcoord_index + 0],
                            1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
                    );
                }

                if(attrib.normals.size()) {
                    vertex.normal = glm::vec3(
                            attrib.normals[3 * index.normal_index + 0],
                            attrib.normals[3 * index.normal_index + 1],
                            attrib.normals[3 * index.normal_index + 2]
                    );
                }

                vertex.color = color;

                outputShape.vertices.push_back(vertex);
                outputShape.indices.push_back(outputShape.indices.size());
            }

            index_offset += fv;
        }
    }

    return outputShape;
}

// ---------------------------------------------------------------------------------------------------------------------

}}