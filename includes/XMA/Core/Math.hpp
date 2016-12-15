#ifndef _XMAGL_CORE_MATH_HPP
#define _XMAGL_CORE_MATH_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

struct Math
{
    static constexpr float PI      = 3.141592654f;
    static constexpr float RAD_PI  = 0.01745329252f; // PI/180
    static constexpr float INV_RAD = 57.29577951f;   // 180/PI

    // Defined some axis
    //
    static glm::vec3 AxisX();
    static glm::vec3 AxisY();
    static glm::vec3 AxisZ();
    static glm::vec3 AxisXY();
    static glm::vec3 AxisXZ();
    static glm::vec3 AxisYZ();

    // Rotate a position around a target by one axis
    //
    // Return the new position
    //
    static glm::vec3 orbit(
            const glm::vec3& position,
            const glm::vec3& target,
            float angle,
            const glm::vec3& axis = AxisY()
    );

    static glm::vec3 orbit(
            const glm::vec3& position,
            const glm::vec3& target,
            const glm::vec2& rotation
    );

    // Apply a friction to value
    //
    static float applyForce(float move, float force);
    static glm::vec2 applyForce(const glm::vec2& move, float force);
    static glm::vec3 applyForce(const glm::vec3& move, float force);

    // Get offset vector between two points with axis restrictions
    //
    // axis = glm::vec3(1.f) >> use all axis
    // axis = glm::vec3(1.f, 0.f, 0.f) >> use only x axis
    // axis = glm::vec3(1.f, 0.f, 1.f) >> use xz axis
    //
    static glm::vec3 getOffset(const glm::vec3& position, const glm::vec3& move, const glm::vec3& axis = glm::vec3(1.f));

    // Get normalized direction vector between two points with axis restrictions
    //
    // axis = glm::vec3(1.f) >> use all axis
    // axis = glm::vec3(1.f, 0.f, 0.f) >> use only x axis
    // axis = glm::vec3(1.f, 0.f, 1.f) >> use xz axis
    //
    static glm::vec3 getDirection(const glm::vec3& position, const glm::vec3& target, const glm::vec3& axis = glm::vec3(1.f));

    // Get angle between two points with origin
    //
    static float getAngle(const glm::vec3& a, const glm::vec3& b, const glm::vec3& origin);

    // Get distance between two points
    //
    static float getDistance(const glm::vec3& a, const glm::vec3& b);

    // Extract position from matrix
    //
    static glm::vec3 getPositionFromMatrix(const glm::mat4& matrix);

    // Generate a random int value
    //
    static int getRandomInt(int from, int to);

    // Generate a random float value
    //
    static float getRandomFloat(float from, float to);

    // Generate a random vec4
    //
    static glm::vec3 getRandomVec3(float from = -1.f, float to = 1.f, const glm::vec3& axis = glm::vec3(1.f));

};

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
