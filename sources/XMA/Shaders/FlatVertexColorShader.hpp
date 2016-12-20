#ifndef _XMAGL_SHADERS_FLATCOLORSHADER_HPP
#define _XMAGL_SHADERS_FLATCOLORSHADER_HPP

#include <XMA/Shader.hpp>

namespace XMA {  namespace Shaders {

// ---------------------------------------------------------------------------------------------------------------------

class FlatVertexColorShader : public Shader
{
    public:

        FlatVertexColorShader()
        {
            compile(getVertexSource(), getFragmentSource());
        }

        virtual std::string getVertexSource() const override
        {
            return (
                "#version 410\n"
                "uniform mat4 __transform;\n"
                "layout(location = 0) in vec3 __position;\n"
                "layout(location = 3) in vec4 __color;\n"
                "out vec4 color;\n"
                "void main() {\n"
                "    color = __color;\n"
                "    gl_Position = __transform * vec4(__position, 1.0);\n"
                "}\n"
            );
        }

        virtual std::string getFragmentSource() const override
        {
            return (
                "#version 410\n"
                "in vec4 color;\n"
                "out vec4 FragColor;\n"
                "void main() {\n"
                "    FragColor = color;\n"
                "}\n"
            );
        }
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
