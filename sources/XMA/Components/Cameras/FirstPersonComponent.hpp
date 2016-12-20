#ifndef _XMAGL_CAMERAS_FIRSTPERSONCOMPONENT_HPP
#define _XMAGL_CAMERAS_FIRSTPERSONCOMPONENT_HPP

#include <XMA/Component.hpp>

namespace XMA { namespace Components { namespace Cameras {

// ---------------------------------------------------------------------------------------------------------------------

class FirstPersonComponent : public Component
{
    public:

        FirstPersonComponent();



        virtual void update(float deltaTime) override;

        FirstPersonComponent& setFlyingMode(bool state = true)
        { m_flyingMode = state; return *this; }

        FirstPersonComponent& setSpeed(float value)
        { m_speed = value; return *this; }

        FirstPersonComponent& setSensitivity(float value)
        { m_sensitivity = value; return *this; }

        FirstPersonComponent& setVerticalResctriction(float value)
        { m_verticalResctriction = value; return *this; }

        virtual void create() override;

    protected:

        glm::vec3 getOrientation(const glm::vec2& relativeMousePosition);

    private:

        Key::Code m_forwardKey { Key::Z };
        Key::Code m_backwardKey { Key::S };
        Key::Code m_leftKey { Key::A };
        Key::Code m_rightKey { Key::E };

        bool m_flyingMode { false };

        float m_verticalResctriction = 1.8f;

        glm::vec3 m_position;
        glm::vec3 m_target;
        glm::vec3 m_orientation;

        glm::vec3 m_move;

        float m_force { 1.f };
        float m_speed { 10.f };
        float m_sensitivity { 0.3f };
        float m_friction { 0.5f };

        float m_phi { 0.f };
        float m_theta { 0.f };
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
