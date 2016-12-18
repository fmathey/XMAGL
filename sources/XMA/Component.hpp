#ifndef _XMAGL_COMPONENT_HPP
#define _XMAGL_COMPONENT_HPP

#include <XMA/Config.hpp>
#include <XMA/Display.hpp>
#include <XMA/Engine.hpp>
#include <XMA/Input.hpp>
#include "Engine.hpp"

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Entity;

// ---------------------------------------------------------------------------------------------------------------------

class Component
{
    friend class Entity;

    public:

        virtual ~Component() {}

        virtual void create() {}
        virtual void update(float deltaTime) {}

        Entity& getEntity();
        Display getDisplay();
        Input getInput();

        float getElapsedTime() const;
        float getFrameTime() const;
        float getDeltaTime() const;
        float getFramesPerSeconds() const;
        float getTimescale() const;

        Component& setTimescale(float scale);


        template <typename T>
        T getDisplay() {
            XMA_ASSERT_STATIC_CLASS(Display, T);
            return T(m_engine->display);
        }

        template <typename T>
        T getInput() {
            XMA_ASSERT_STATIC_CLASS(Input, T);
            return T(m_engine->input);
        }

    private:

        Entity* m_entity;

        engine_t* m_engine { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
