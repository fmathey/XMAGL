#ifndef _XMAGL_DEBUG_HPP
#define _XMAGL_DEBUG_HPP

#include <XMA/Config.hpp>

#if XMA_DEBUG

    namespace XMA {

    // -----------------------------------------------------------------------------------------------------------------

    struct Shape;

    // -----------------------------------------------------------------------------------------------------------------

    class Debug
    {
        public:

            static void log();

            template <typename T>
            static void log(T value)
            { m_stream << value << std::endl; }

            template <typename T>
            static void log(const std::string& key, T value)
            { m_stream << key << ": " << value << std::endl; }

            static void log(const std::string& str);
            static void log(const glm::vec2& vec);
            static void log(const glm::vec3& vec);
            static void log(const glm::vec4& vec);
            static void log(const glm::mat4& mat);
            static void log(const glm::quat& quat);

            static void log(const std::string& key, const glm::vec2& vec);
            static void log(const std::string& key, const glm::vec3& vec);
            static void log(const std::string& key, const glm::vec4& vec);
            static void log(const std::string& key, const glm::mat4& mat);
            static void log(const std::string& key, const glm::quat& quat);
            static void log(const Shape& shape);

            static void dump();

        private:

            static std::ostringstream m_stream;
    };

    // -----------------------------------------------------------------------------------------------------------------

    }

    #define XMA_LOG(VALUE) XMA::Debug::log(VALUE);
    #define XMA_LOGKEY(KEY, VALUE) XMA::Debug::log(KEY, VALUE);
    #define XMA_DUMP_LOG() XMA::Debug::dump();
#else
    #define XMA_LOG(VALUE)
    #define XMA_LOGKEY(KEY, VALUE)
    #define XMA_DUMP_LOG()
#endif

#endif