#include <XMA/Components/Cameras/FirstPersonComponent.hpp>

#include <XMA/Math.hpp>

namespace XMA {  namespace Components { namespace Cameras {

// ---------------------------------------------------------------------------------------------------------------------

FirstPersonComponent::FirstPersonComponent()
{}

// ---------------------------------------------------------------------------------------------------------------------

void FirstPersonComponent::create()
{
    m_position = getCamera().getPosition();

    m_phi = -50;
}

// ---------------------------------------------------------------------------------------------------------------------

void FirstPersonComponent::update(float deltaTime)
{
    Input& input = getInput();

    if(input.isKeyPressed(m_forwardKey))  m_move.z =  m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_backwardKey)) m_move.z = -m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_leftKey))     m_move.x =  m_force * m_speed * deltaTime;
    if(input.isKeyPressed(m_rightKey))    m_move.x = -m_force * m_speed * deltaTime;

    // Orientation

    if(input.isMouseMove()) {
        m_orientation = getOrientation(input.getMouseMove() * m_sensitivity);
    }

    // Position

    m_position += (m_move.z * m_orientation) + glm::cross(getCamera().getVerticalAxis(), m_move.x * m_orientation);

    if(!m_flyingMode) {
        m_position.y = m_verticalResctriction;
    }

    m_target = m_position + m_orientation;

    // Update camera

    getCamera().setPosition(m_position).setTarget(m_target);

    // Deceleration

    m_move = Math::applyForce(m_move, m_friction * deltaTime);
}

// ---------------------------------------------------------------------------------------------------------------------

glm::vec3 FirstPersonComponent::getOrientation(const glm::vec2& relativeMousePosition)
{
    glm::vec3 orientation;

    m_phi -= relativeMousePosition.y;
    m_theta -= relativeMousePosition.x;

    m_phi = glm::clamp(m_phi, -89.f, 89.f);

    float phiRadian = m_phi * Math::RAD_PI;
    float thetaRadian = m_theta * Math::RAD_PI;

    if(getCamera().getVerticalAxis().x == 1.0){
        orientation.x = glm::sin(phiRadian);
        orientation.y = glm::cos(phiRadian) * glm::cos(thetaRadian);
        orientation.z = glm::cos(phiRadian) * glm::sin(thetaRadian);
    }
    else if(getCamera().getVerticalAxis().y == 1.0){
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