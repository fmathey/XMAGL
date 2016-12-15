#ifndef _XMAGL_CORE_CONTROLLER_HPP
#define _XMAGL_CORE_CONTROLLER_HPP

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Engine;

// ---------------------------------------------------------------------------------------------------------------------

class Controller
{
    public:

        virtual ~Controller() {}

        virtual void create() {};
        virtual void update(float deltaTime) {};
        virtual void render() {};
        virtual void dispose() {};

        Engine& getEngine();

        Controller& setEngine(Engine& engine);

    private:

        Engine* m_engine;

};

// ---------------------------------------------------------------------------------------------------------------------

using ControllerUptr = std::unique_ptr<Controller>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
