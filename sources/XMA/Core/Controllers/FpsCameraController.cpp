#include <XMA/Core/Controllers/FpsCameraController.hpp>

#include <XMA/Core/Math.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------


FpsCameraController::FpsCameraController(const Camera& camera) : m_camera(camera)
{}

// ---------------------------------------------------------------------------------------------------------------------

void FpsCameraController::create()
{
    m_camera.setAspect(getEngine().getDisplay().getAspect());
}

// ---------------------------------------------------------------------------------------------------------------------

void FpsCameraController::update(float deltaTime)
{
    Input& input = getEngine().getInput();

    if(input.isKeyPressed(m_forwardKey))  m_move.z =  m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_backwardKey)) m_move.z = -m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_leftKey))     m_move.x =  m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_rightKey))    m_move.x = -m_force * m_speed * deltaTime;

    // Orientation

    if(input.isMouseMove()) {
        m_orientation = getOrientation(input.getMouseMove() * m_sensitivity * deltaTime);
    }

    // Position

    m_position += (m_move.z * m_orientation) + glm::cross(m_camera.getVerticalAxis(), m_move.x * m_orientation);

    if(!m_flyingMode) {
        m_position.y = m_verticalResctriction;
    }

    m_target = m_position + m_orientation;

    // Update camera

    getEngine().setCameraMatrix(m_camera.setPosition(m_position).setTarget(m_target).getMatrix());

    // Deceleration

    m_move = Math::applyForce(m_move, m_friction * deltaTime);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 FpsCameraController::getOrientation(const glm::vec2& relativeMousePosition)
{
    glm::vec3 orientation;

    m_phi -= relativeMousePosition.y;
    m_theta -= relativeMousePosition.x;

    m_phi = glm::clamp(m_phi, -89.f,89.f);

    float phiRadian = m_phi * Math::RAD_PI;
    float thetaRadian = m_theta * Math::RAD_PI;

    if(m_camera.getVerticalAxis().x == 1.0){
        orientation.x = glm::sin(phiRadian);
        orientation.y = glm::cos(phiRadian) * glm::cos(thetaRadian);
        orientation.z = glm::cos(phiRadian) * glm::sin(thetaRadian);
    }
    else if(m_camera.getVerticalAxis().y == 1.0){
        orientation.x = glm::cos(phiRadian) * glm::sin(thetaRadian);
        orientation.y = glm::sin(phiRadian);
        orientation.z = glm::cos(phiRadian) * glm::cos(thetaRadian);
    }
    else
    {
        orientation.x = glm::cos(phiRadian) * glm::cos(thetaRadian);
        orientation.y = glm::cos(phiRadian) * glm::sin(thetaRadian);
        orientation.z = glm::sin(phiRadian);
    }

    return orientation;
}

// ---------------------------------------------------------------------------------------------------------------------

}}}