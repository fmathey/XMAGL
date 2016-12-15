#ifndef _XMAGL_CORE_SHADERDATA_HPP
#define _XMAGL_CORE_SHADERDATA_HPP

#include <XMA/Core/Shader.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Shader::Data
{
    GLuint program{0};
    GLuint vertexShader{0};
    GLuint fragmentShader{0};

    std::map<std::string, GLint> uniforms;

    void dispose()
    {
        glDetachShader(program, vertexShader);
        glDetachShader(program, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteProgram(program);
    }
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
