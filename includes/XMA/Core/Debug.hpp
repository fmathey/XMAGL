#ifndef _XMAGL_CORE_DEBUG_HPP
#define _XMAGL_CORE_DEBUG_HPP

#include <XMA/Core/Config.hpp>
//#include <XMA/Shape.hpp>

#if XMA_DEBUG

    namespace XMA { namespace Core {

    // -----------------------------------------------------------------------------------------------------------------

    class Debug
    {
        public:

            static void log()
            { m_stream << std::endl; }

            template <typename T>
            static void log(T value)
            { m_stream << value << std::endl; }

            static void log(const std::string& str)
            { m_stream << str << std::endl; }

            static void log(const glm::vec2& vec)
            { log(glm::to_string(vec)); }

            static void log(const glm::vec3& vec)
            { log(glm::to_string(vec)); }

            static void log(const glm::vec4& vec)
            { log(glm::to_string(vec)); }

            static void log(const glm::mat4& mat)
            { log(glm::to_string(mat)); }

            static void log(const glm::quat& quat)
            { log(glm::to_string(quat)); }

            template <typename T>
            static void log(const std::string& key, T value)
            { m_stream << key << ": " << value << std::endl; }

            static void log(const std::string& key, const glm::vec2& vec)
            { log(key, glm::to_string(vec)); }

            static void log(const std::string& key, const glm::vec3& vec)
            { log(key, glm::to_string(vec)); }

            static void log(const std::string& key, const glm::vec4& vec)
            { log(key, glm::to_string(vec)); }

            static void log(const std::string& key, const glm::mat4& mat)
            { log(key, glm::to_string(mat)); }

            static void log(const std::string& key, const glm::quat& quat)
            { log(key, glm::to_string(quat)); }

    //        static void log(const Shape& shape)
    //        {
    //            m_stream << std::endl;
    //            for(auto i(0u); i < shape.vertices.size(); i++) {
    //                m_stream
    //                        << "\tvertices.push_back(Vertex(" << std::endl
    //                        << "\t\tglm::" << glm::to_string(shape.vertices[i].position) << "," << std::endl
    //                        << "\t\tglm::" << glm::to_string(shape.vertices[i].normal) << "," << std::endl
    //                        << "\t\tglm::" << glm::to_string(shape.vertices[i].texcoord) << "," << std::endl
    //                        << "\t\tglm::" << glm::to_string(shape.vertices[i].color) << std::endl
    //                        << "\t));" << std::endl
    //                        << "\tindices.push_back(" << i << ");" << std::endl;
    //            }
    //            m_stream << std::endl;
    //        }

            static void dump()
            { std::cout << m_stream.str(); }

        private:

            static std::ostringstream m_stream;
    };

    // -----------------------------------------------------------------------------------------------------------------

    }}

    #define XMA_LOG(VALUE) XMA::Core::Debug::log(VALUE);
    #define XMA_LOGKEY(KEY, VALUE) XMA::Core::Debug::log(KEY, VALUE);
    #define XMA_DUMP_LOG() XMA::Core::Debug::dump();
#else
    #define XMA_LOG(VALUE)
    #define XMA_LOGKEY(KEY, VALUE)
    #define XMA_DUMP_LOG()
#endif

#endif