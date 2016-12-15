#include <XMA/Core/Controllers/ArcballCameraController.hpp>

#include <XMA/Core/Math.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

ArcballCameraController::ArcballCameraController(const Camera& camera) : m_camera(camera)
{}

// ---------------------------------------------------------------------------------------------------------------------

void ArcballCameraController::create()
{
    glm::vec3 p(m_camera.getPosition() * Math::AxisYZ());
    glm::vec3 t(m_camera.getTarget() * Math::AxisYZ());

    m_camera.setAspect(getEngine().getDisplay().getAspect());

    getEngine().setCameraMatrix(m_camera.setPosition(p).setTarget(t).getMatrix());
}

// ---------------------------------------------------------------------------------------------------------------------

void ArcballCameraController::update(float deltaTime)
{
    Input& input { getEngine().getInput() };

    if(input.isKeyPressed(m_forwardKey))  m_move.z = -m_moveForce * deltaTime;
    if(input.isKeyPressed(m_backwardKey)) m_move.z =  m_moveForce * deltaTime;
    if(input.isKeyPressed(m_leftKey))     m_move.x = -m_moveForce * deltaTime;
    if(input.isKeyPressed(m_rightKey))    m_move.x =  m_moveForce * deltaTime;

    if(input.isMouseButtonPressed(m_rotationButton)) {
        m_yaw = 0.f;
        m_pitch = 0.f;
        if(input.isMouseMove()) {
            glm::vec2 mouseMove = glm::normalize(input.getMouseMove());
            m_yaw = mouseMove.x * m_yawForce * m_sensibility * deltaTime;
            m_pitch = mouseMove.y * m_pitchForce * m_sensibility * deltaTime;
        }
    }

    if(input.isMouseScroll()) {
        m_zoom = input.getMouseScroll().y * m_zoomForce * m_sensibility * deltaTime;
    }

    getEngine().setWorldMatrix(
            glm::rotate(m_yaw, Math::AxisY()) *
            glm::translate(m_move) *
            getEngine().getWorldMatrix()
    );

    getEngine().setCameraMatrix(
            glm::rotate(getEngine().getCameraMatrix(), m_pitch, Math::AxisX()) *
            glm::translate(m_camera.getDirection() * m_zoom)
    );

    m_move  = Math::applyForce(m_move, m_moveFriction * deltaTime);
    m_yaw   = Math::applyForce(m_yaw, m_yawFriction * deltaTime);
    m_pitch = Math::applyForce(m_pitch, m_pitchFriction * deltaTime);
    m_zoom  = Math::applyForce(m_zoom, m_zoomFriction * deltaTime);
}

// ---------------------------------------------------------------------------------------------------------------------

}}}