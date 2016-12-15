#ifndef _XMAGL_CORE_TRANSFORM_HPP
#define _XMAGL_CORE_TRANSFORM_HPP

#include <XMA/Core/Config.hpp>
#include <XMA/Core/Math.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Transform
{
    public:

        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scale;

        Transform(
                const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
                const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f),
                const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)
        );

        virtual ~Transform() {}

        glm::mat4 getMatrix() const;

        float getDistance(const glm::vec3& target) const;
        float getDistance(const Transform& target) const;

        glm::vec3 getDirection(const glm::vec3& target) const;
        glm::vec3 getDirection(const Transform& target) const;

        Transform& lookAt(const glm::vec3& target, const glm::vec3& axis = Math::AxisY());


        // Helpers

        static Transform Position(const glm::vec3& position);
        static Transform Rotation(const glm::vec3& rotation);
        static Transform Scale(const glm::vec3& scale);

};

// ---------------------------------------------------------------------------------------------------------------------

typedef std::unique_ptr<Transform> TransformUptr;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
