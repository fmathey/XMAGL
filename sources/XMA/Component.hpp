#ifndef _XMAGL_COMPONENT_HPP
#define _XMAGL_COMPONENT_HPP

#include <XMA/Config.hpp>
#include <XMA/Engine.hpp>

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
        Display& getDisplay();
        Input& getInput();
        Camera& getCamera();

        float getElapsedTime() const;
        float getFrameTime() const;
        float getDeltaTime() const;
        float getFramesPerSeconds() const;
        float getTimescale() const;

        Component& setTimescale(float scale);

    private:

        Entity* m_entity { nullptr };
        Engine* m_engine { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
