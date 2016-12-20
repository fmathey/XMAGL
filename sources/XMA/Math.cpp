#include <XMA/Math.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::AxisX()  { return glm::vec3(1.f, 0.f, 0.f); }
glm::vec3 Math::AxisY()  { return glm::vec3(0.f, 1.f, 0.f); }
glm::vec3 Math::AxisZ()  { return glm::vec3(0.f, 0.f, 1.f); }
glm::vec3 Math::AxisXY() { return glm::vec3(1.f, 1.f, 0.f); }
glm::vec3 Math::AxisXZ() { return glm::vec3(1.f, 0.f, 1.f); }
glm::vec3 Math::AxisYZ() { return glm::vec3(0.f, 1.f, 1.f); }

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::orbit(
        const glm::vec3 &position,
        const glm::vec3 &target,
        float angle,
        const glm::vec3 &axis
)
{
//    return glm::vec3(glm::rotate(angle, axis) * glm::vec4(position - target, 0.f));

    return glm::vec3(glm::mat4_cast(glm::angleAxis(angle, axis)) * glm::vec4(position - target, 0.f));
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::orbit(const glm::vec3 &position, const glm::vec3 &target, const glm::vec2 &rotation)
{
    glm::vec3 newPosition = position;
    newPosition = orbit(newPosition, target, rotation.x, AxisY());
    newPosition = orbit(newPosition, target, rotation.y, AxisX());
    return newPosition;
}

// ---------------------------------------------------------------------------------------------------------------------

float Math::applyForce(float move, float force)
{
    if(move > force) {
        return move - force;
    }

    if(move < -force) {
        return move + force;
    }

    return 0.f;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec2 Math::applyForce(const glm::vec2 &move, float force)
{
    glm::vec2 res = move;
    res.x = applyForce(res.x, force);
    res.y = applyForce(res.y, force);
    return res;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::applyForce(const glm::vec3 &move, float force)
{
    glm::vec3 res = move;
    res.x = applyForce(res.x, force);
    res.y = applyForce(res.y, force);
    res.z = applyForce(res.z, force);
    return res;
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::getOffset(const glm::vec3 &position, const glm::vec3 &target, const glm::vec3 &axis)
{
    return (target * axis) - (position * axis);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::getDirection(const glm::vec3 &position, const glm::vec3 &target, const glm::vec3 &axis)
{
    return glm::normalize(getOffset(position, target, axis));
}

// ---------------------------------------------------------------------------------------------------------------------

float Math::getAngle(const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &origin)
{
    return acos(glm::dot(glm::normalize(a - origin), glm::normalize(b - origin)));
}

// ---------------------------------------------------------------------------------------------------------------------

float Math::getDistance(const glm::vec3 &a, const glm::vec3 &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::getPositionFromMatrix(const glm::mat4 & matrix)
{
    // Get the 3 basis vector planes at the camera origin and transform them into model space.
    //
    // NOTE: Planes have to be transformed by the inverse transpose of a matrix
    //       Nice reference here: http://www.opengl.org/discussion_boards/showthread.php/159564-Clever-way-to-transform-plane-by-matrix
    //
    //       So for a transform to model space we need to do:
    //            inverse(transpose(inverse(MV)))
    //       This equals : transpose(MV) - see Lemma 5 in http://mathrefresher.blogspot.com.au/2007/06/transpose-of-matrix.html
    //
    // As each plane is simply (1,0,0,0), (0,1,0,0), (0,0,1,0) we can pull the data directly from the transpose matrix.
    //
    glm::mat4 matrixT = glm::transpose(matrix);

    // Get plane normals
    glm::vec3 n1(matrixT[0]);
    glm::vec3 n2(matrixT[1]);
    glm::vec3 n3(matrixT[2]);

    // Get plane distances
    float d1(matrixT[0].w);
    float d2(matrixT[1].w);
    float d3(matrixT[2].w);

    // Get the intersection of these 3 planes
    // http://paulbourke.net/geometry/3planes/
    glm::vec3 n2n3 = glm::cross(n2, n3);
    glm::vec3 n3n1 = glm::cross(n3, n1);
    glm::vec3 n1n2 = glm::cross(n1, n2);

    glm::vec3 top = (n2n3 * d1) + (n3n1 * d2) + (n1n2 * d3);

    return top / -glm::dot(n1, n2n3);
}

// ---------------------------------------------------------------------------------------------------------------------

int Math::getRandomInt(int from, int to)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from, to);
    return dist6(rng);
}

// ---------------------------------------------------------------------------------------------------------------------

float Math::getRandomFloat(float from, float to)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(from, to);
    return dis(gen);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 Math::getRandomVec3(float from, float to, const glm::vec3& axis)
{
    return glm::vec3(
            getRandomFloat(from, to),
            getRandomFloat(from, to),
            getRandomFloat(from, to)
    ) * axis;
}

// ---------------------------------------------------------------------------------------------------------------------

}