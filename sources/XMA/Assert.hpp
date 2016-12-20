#ifndef _XMAGL_ASSERT_HPP
#define _XMAGL_ASSERT_HPP

#include <XMA/Config.hpp>

namespace XMA
{

// ---------------------------------------------------------------------------------------------------------------------

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

inline void _assert(const char* expression, const char* file, int line, const std::string& message = "")
{
    if(message != "") {
        throw std::runtime_error(message);
    } else {
        std::ostringstream s;
        s << "Assertion '" << expression << "' failed, ";
        s << "file '" << file << "' ";
        s << "line '" << line << "'.";
        throw std::runtime_error(s.str());
    }
}

inline void _assert_file_exists(const std::string& filename, const char* file, int line)
{
    std::ifstream f(filename.c_str());

    if(!f.good()) {
        std::ostringstream s;
        s << "File '" << filename << "' not found, ";
        s << "file '" << file << "' ";
        s << "line '" << line << "'.";
        throw std::runtime_error(s.str());
    }
}

// ---------------------------------------------------------------------------------------------------------------------

}

#define XMA_ASSERT(EXPRESSION) ((EXPRESSION) ? (void)0 : XMA::_assert(#EXPRESSION, __FILE__, __LINE__));
#define XMA_ASSERT_STATIC_CLASS(BASE, T) static_assert(std::is_base_of<BASE, T>::value, "T must inherit from "#BASE );
#define XMA_ASSERT_INSTANCE(TYPE, VALUE) XMA_ASSERT(XMA::instanceof<TYPE>(VALUE));
#define XMA_ASSERT_MSG(EXPRESSION, MESSAGE) ((EXPRESSION) ? (void)0 : XMA::_assert(#EXPRESSION, __FILE__, __LINE__, MESSAGE));
#define XMA_ASSERT_FILE_EXISTS(FILENAME) XMA::_assert_file_exists(FILENAME, __FILE__, __LINE__);

// ---------------------------------------------------------------------------------------------------------------------

#endif
