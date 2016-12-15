#ifndef _XMAGL_CORE_CONTROLLERS_ARCBALLCAMERACONTROLLER_HPP
#define _XMAGL_CORE_CONTROLLERS_ARCBALLCAMERACONTROLLER_HPP

#include <XMA/Core/Controller.hpp>
#include <XMA/Core/Camera.hpp>
#include <XMA/Core/Input.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

class ArcballCameraController : public Controller
{
    public:

        ArcballCameraController(const Camera& camera = Camera());

        virtual void create() override;
        virtual void update(float deltaTime) override;

    private:

        Key::Code m_forwardKey { Key::Z };
        Key::Code m_backwardKey { Key::S };
        Key::Code m_leftKey { Key::A };
        Key::Code m_rightKey { Key::E };

        Mouse::Button m_rotationButton { Mouse::LEFT };

        glm::vec3 m_move;
        float m_moveForce { 25.0f };
        float m_moveFriction { 2.f };

        float m_sensibility { 1.f };

        float m_zoom { 0.f };
        float m_zoomForce { 10.f };
        float m_zoomFriction { 1.5f };

        float m_yaw { 0.f };
        float m_yawForce { 3.f };
        float m_yawFriction { 0.2f };

        float m_pitch { 0 };
        float m_pitchForce { 3.f };
        float m_pitchFriction { 0.2f };

        Camera m_camera;
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
