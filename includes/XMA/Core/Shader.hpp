#ifndef _XMAGL_CORE_SHADER_HPP
#define _XMAGL_CORE_SHADER_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Shader
{ 
    XMA_PRIVATE_DATA();

    public:

        Shader();

        Shader(const Shader& copy);

        virtual ~Shader();

        virtual std::string getVertexSource() const;
        virtual std::string getFragmentSource() const;

        Shader& validate();

        GLint getUniformId(const std::string& key) const;

        Shader& setUniform1i(GLint id, int val);
        Shader& setUniform1f(GLint id, float val);
        Shader& setUniform3f(GLint id, const glm::vec3& vec3);
        Shader& setUniform4f(GLint id, const glm::vec4& vec4);
        Shader& setUniformMat4fv(GLint id, const glm::mat4& mat4);

        Shader& setUniform1i(const std::string& key, int val);
        Shader& setUniform1f(const std::string& key, float val);
        Shader& setUniform3f(const std::string& key, const glm::vec3& vec3);
        Shader& setUniform4f(const std::string& key, const glm::vec4& vec4);
        Shader& setUniformMat4fv(const std::string& key, const glm::mat4& mat4);

        Shader& setTransform(const glm::mat4& mat4);

    protected:

        Shader& activate();
        Shader& compile(const std::string& vs, const std::string& fs);
};

// ---------------------------------------------------------------------------------------------------------------------

using ShaderUptr = std::unique_ptr<Shader>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
