#include <XMA/Transform.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Transform::Transform(const glm::vec3& p, const glm::vec3& r, const glm::vec3& s)
        : position(p), rotation(r), scale(s)
{

}

// ---------------------------------------------------------------------------------------------------------------------

glm::mat4 Transform::getMatrix() const
{
    glm::mat4 matrix;

    matrix *= glm::translate(position * glm::vec3(-1.f, 1.f, 1.f));
    matrix *= glm::toMat4(rotation);
    matrix *= glm::scale(scale);

    return matrix;
}

// ---------------------------------------------------------------------------------------------------------------------

float Transform::getDistance(const glm::vec3 &target) const
{
    return Math::getDistance(position, target);
}

// ---------------------------------------------------------------------------------------------------------------------

float Transform::getDistance(const Transform& target) const
{
    return getDistance(target.position);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Transform::getDirection(const glm::vec3& target) const
{
    return Math::getDirection(position, target);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Transform::getDirection(const Transform& target) const
{
    return getDirection(target.position);
}

// ---------------------------------------------------------------------------------------------------------------------

Transform& Transform::lookAt(const glm::vec3& target, const glm::vec3& axis)
{
    rotation = glm::toQuat(glm::lookAt(position, target, axis));
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Transform Transform::Position(const glm::vec3& v)
{
    Transform t;
    t.position = v;
    return t;
}

// ---------------------------------------------------------------------------------------------------------------------

Transform Transform::Rotation(const glm::vec3& v)
{
    Transform t;
    t.rotation = v;
    return t;
}

// ---------------------------------------------------------------------------------------------------------------------

Transform Transform::Scale(const glm::vec3& v)
{
    Transform t;
    t.scale = v;
    return t;
}

// ---------------------------------------------------------------------------------------------------------------------

}