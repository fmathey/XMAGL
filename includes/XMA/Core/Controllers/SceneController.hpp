#ifndef _XMAGL_CORE_CONTROLLERS_SCENECONTROLLER_HPP
#define _XMAGL_CORE_CONTROLLERS_SCENECONTROLLER_HPP

#include <XMA/Core/Controller.hpp>
#include <XMA/Core/Scene.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

class SceneController : public Controller
{
    public:

        virtual void update(float deltaTime) override;

        virtual void render() override;

        virtual void dispose() override;

        template<typename T, typename... TArgs>
        T& setScene(TArgs&&... mArgs)
        {
            if(m_scene != nullptr) m_scene->dispose();

            static_assert(std::is_base_of<Scene, T>::value, "T must inherit from Scene");

            T* scene(new T(std::forward<TArgs>(mArgs)...));
            scene->setEngine(getEngine());
            std::unique_ptr<Scene> uPtr{scene};

            m_scene = std::move(uPtr);

            m_scene->create();

            return *scene;
        }

    private:

        SceneUptr m_scene { nullptr };
};

// ---------------------------------------------------------------------------------------------------------------------

}}}

#endif
