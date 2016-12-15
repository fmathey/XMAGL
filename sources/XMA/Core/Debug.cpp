#include <XMA/Core/Debug.hpp>
#include <XMA/Core/Shape.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

#if XMA_DEBUG

std::ostringstream Debug::m_stream;

// ---------------------------------------------------------------------------------------------------------------------

void Debug::log() { m_stream << std::endl; }
void Debug::log(const std::string& str) { m_stream << str << std::endl; }
void Debug::log(const glm::vec2& vec) { log(glm::to_string(vec)); }
void Debug::log(const glm::vec3& vec) { log(glm::to_string(vec)); }
void Debug::log(const glm::vec4& vec) { log(glm::to_string(vec)); }
void Debug::log(const glm::mat4& mat) { log(glm::to_string(mat)); }
void Debug::log(const glm::quat& quat) { log(glm::to_string(quat)); }
void Debug::log(const std::string& key, const glm::vec2& vec) { log(key, glm::to_string(vec)); }
void Debug::log(const std::string& key, const glm::vec3& vec) { log(key, glm::to_string(vec)); }
void Debug::log(const std::string& key, const glm::vec4& vec) { log(key, glm::to_string(vec)); }
void Debug::log(const std::string& key, const glm::mat4& mat) { log(key, glm::to_string(mat)); }
void Debug::log(const std::string& key, const glm::quat& quat) { log(key, glm::to_string(quat)); }

void Debug::log(const Shape& shape)
{
    m_stream << std::endl;
    for(auto i(0u); i < shape.vertices.size(); i++) {
        m_stream
                << "\tvertices.push_back(Vertex(" << std::endl
                << "\t\tglm::" << glm::to_string(shape.vertices[i].position) << "," << std::endl
                << "\t\tglm::" << glm::to_string(shape.vertices[i].normal) << "," << std::endl
                << "\t\tglm::" << glm::to_string(shape.vertices[i].texcoord) << "," << std::endl
                << "\t\tglm::" << glm::to_string(shape.vertices[i].color) << std::endl
                << "\t));" << std::endl
                << "\tindices.push_back(" << i << ");" << std::endl;
    }
    m_stream << std::endl;
}

void Debug::dump() { std::cout << m_stream.str(); }

#endif

// ---------------------------------------------------------------------------------------------------------------------

}}
