#include <XMA/Shader.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

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

Shader::Shader()
{
    m_data = std::unique_ptr<Data>(new Data);

    compile(getVertexSource(), getFragmentSource());
}

// ---------------------------------------------------------------------------------------------------------------------

Shader::Shader(const Shader& copy)
{
    m_data = std::unique_ptr<Data>(new Data);

    compile(copy.getVertexSource(), copy.getFragmentSource());
}

// ---------------------------------------------------------------------------------------------------------------------

Shader::~Shader()
{
    m_data->dispose();
}

// ---------------------------------------------------------------------------------------------------------------------

std::string Shader::getVertexSource() const
{
    return (
        "#version 410\n"
        "uniform mat4 __transform;\n"
        "layout(location = 0) in vec3 __position;\n"
        "layout(location = 2) in vec3 __normal;\n"
        "layout(location = 3) in vec4 __color;\n"
        "out vec3 normal;\n"
        "out vec4 color;\n"
        "void main() {\n"
        "    color         = __color;\n"
        "    normal        = (__transform * vec4(__normal, 0.0)).xyz;\n"
        "    gl_Position   = __transform * vec4(__position, 1.0);\n"
        "}\n"
    );
}

// ---------------------------------------------------------------------------------------------------------------------

std::string Shader::getFragmentSource() const
{
    return (
        "#version 410\n"
        "in vec3 normal;\n"
        "in vec4 color;\n"
        "out vec4 output_color;\n"
        "void main() {\n"
        "    output_color = color * clamp(dot(-vec3(0, 0, 1), normal), 0.0, 1.0);\n"
        "}\n"
    );
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::compile(const std::string& vs, const std::string& fs)
{
    m_data->dispose();

    m_data->vertexShader = CreateShader(vs, GL_VERTEX_SHADER);
    m_data->fragmentShader = CreateShader(fs, GL_FRAGMENT_SHADER);

    m_data->program = glCreateProgram();

    glAttachShader(m_data->program, m_data->vertexShader);
    glAttachShader(m_data->program, m_data->fragmentShader);

    glLinkProgram(m_data->program);

    CheckShaderError(m_data->program, GL_LINK_STATUS, true, "Shader program linking error");

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::activate()
{
    glUseProgram(m_data->program);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::validate()
{
    glValidateProgram(m_data->program);

    CheckShaderError(m_data->program, GL_VALIDATE_STATUS, true, "Shader program validation error");

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

GLint Shader::getUniformId(const std::string &key) const
{
    if(m_data->uniforms.count(key) == 0) {
        m_data->uniforms[key] = glGetUniformLocation(m_data->program, key.c_str());
    }
    return m_data->uniforms[key];
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform1i(GLint id, int val)
{
    activate();
    glUniform1i(id, val);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform1i(const std::string& key, int val)
{
    return setUniform1i(getUniformId(key), val);
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform1f(GLint id, float val)
{
    activate();
    glUniform1f(id, val);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform1f(const std::string& key, float val)
{
    return setUniform1f(getUniformId(key), val);
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform3f(GLint id, const glm::vec3 &vec3)
{
    activate();
    glUniform3f(id, vec3.x, vec3.y, vec3.z);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform3f(const std::string& key, const glm::vec3& vec3)
{
    return setUniform3f(getUniformId(key), vec3);
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform4f(GLint id, const glm::vec4 &vec4)
{
    activate();
    glUniform4f(id, vec4.x, vec4.y, vec4.z, vec4.a);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniform4f(const std::string& key, const glm::vec4& vec4)
{
    return setUniform4f(getUniformId(key), vec4);
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniformMat4fv(GLint id, const glm::mat4& mat4)
{
    activate();
    glUniformMatrix4fv(id, 1, GL_FALSE, &mat4[0][0]);
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setUniformMat4fv(const std::string& key, const glm::mat4& mat4)
{
    return setUniformMat4fv(getUniformId(key), mat4);
}

// ---------------------------------------------------------------------------------------------------------------------

Shader& Shader::setTransform(const glm::mat4& mat4)
{
    return setUniformMat4fv("__transform", mat4);
}


// ---------------------------------------------------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------------------------------------------------

GLuint CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    if (shader == 0) {
        throw std::runtime_error("Shader creation error");
    }

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation error");

    return shader;
}

// ---------------------------------------------------------------------------------------------------------------------

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint succes = 0;
    GLchar error[1024] = { 0 };

    if (isProgram) {
        glGetProgramiv(shader, flag, &succes);
    } else {
        glGetShaderiv(shader, flag, &succes);
    }

    if (succes == GL_FALSE) {
        if (isProgram) {
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        } else {
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }
        throw std::runtime_error("Shader validation error : " + std::string(error));
    }
}

// ---------------------------------------------------------------------------------------------------------------------

}