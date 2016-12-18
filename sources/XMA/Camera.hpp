#ifndef _XMAGL_CAMERA_HPP
#define _XMAGL_CAMERA_HPP

#include <XMA/Config.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Camera
{
    public:

        Camera();
        virtual ~Camera();

        Camera& setFovy(float value);
        Camera& setAspect(float value);
        Camera& setAspect(const glm::vec2& v);
        Camera& setNear(float value);
        Camera& setFar(float value);
        Camera& setPosition(const glm::vec3& position);
        Camera& setTarget(const glm::vec3& target);
        Camera& setVerticalAxis(const glm::vec3& verticalAxis);

        glm::vec3 getPosition() const;
        glm::vec3 getTarget() const;
        glm::vec3 getVerticalAxis() const;
        glm::vec3 getDirection() const;

        float getFovy() const;
        float getAspect() const;
        float getNear() const;
        float getFar() const;

        glm::mat4 getMatrix() const;

    private:

        float m_fovy;
        float m_aspect;
        float m_near;
        float m_far;

        glm::vec3 m_position;
        glm::vec3 m_target;
        glm::vec3 m_verticalAxis;
};

// ---------------------------------------------------------------------------------------------------------------------

using CameraUptr = std::unique_ptr<Camera>;

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
