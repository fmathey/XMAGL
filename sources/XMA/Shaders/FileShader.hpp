#ifndef _XMAGL_SHADERS_FILESHADER_HPP
#define _XMAGL_SHADERS_FILESHADER_HPP

#include <XMA/Shader.hpp>

namespace XMA {  namespace Shaders {

// ---------------------------------------------------------------------------------------------------------------------

class FileShader : public Shader
{
    public:

        FileShader(const std::string& vsFile, const std::string& fsFile)
        {
            XMA_ASSERT_FILE_EXISTS(vsFile);
            XMA_ASSERT_FILE_EXISTS(fsFile);

            {
                std::ifstream t(vsFile);
                std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                m_vs = str;
            }

            {
                std::ifstream t(fsFile);
                std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                m_fs = str;
            }

            compile(getVertexSource(), getFragmentSource());
        }

        virtual std::string getVertexSource() const override
        {
            return m_vs;
        }

        virtual std::string getFragmentSource() const override
        {
            return m_fs;
        }

    private:

        std::string m_vs;
        std::string m_fs;
};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
