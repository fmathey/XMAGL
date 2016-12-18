#ifndef _XMAGL_SHADERS_GRIDSHADER_HPP
#define _XMAGL_SHADERS_GRIDSHADER_HPP

#include <XMA/Shader.hpp>

namespace XMA {  namespace Shaders {

// ---------------------------------------------------------------------------------------------------------------------

class GridShader : public Shader
{
    public:

        GridShader()
        {
            compile(getVertexSource(), getFragmentSource());
        }

        virtual std::string getVertexSource() const override
        {
            return (
                "#version 410\n"
                "uniform mat4 __transform;\n"
                "layout(location = 0) in vec3 __position;\n"
                "out vec3 position;\n"
                "void main() {\n"
                "    position = __position;\n"
                "    gl_Position = __transform * vec4(__position, 1.0);\n"
                "}\n"
            );
        }

        virtual std::string getFragmentSource() const override
        {
            return (
                "#version 410\n"
                "out vec4 FragColor;\n"
                "in vec2 texcoord;\n"
                "in vec3 position;\n"
                "void main() {\n"
                "    vec2 coord = position.xz;\n"
                "    vec2 grid = abs(fract(coord - 0.5) - 0.5) / fwidth(coord);\n"
                "    float line = min(grid.x, grid.y);\n"
                "    FragColor = vec4(vec3(1.0), (1.0 - min(line, 1.0))*0.2);\n"
                "}\n"
            );
        }
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
