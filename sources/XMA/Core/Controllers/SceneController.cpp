#include <XMA/Core/Controllers/SceneController.hpp>

namespace XMA { namespace Core { namespace Controllers {

// ---------------------------------------------------------------------------------------------------------------------

void SceneController::update(float deltaTime)
{
    if(m_scene != nullptr) m_scene->update(deltaTime);
}

// ---------------------------------------------------------------------------------------------------------------------

void SceneController::render()
{
    if(m_scene != nullptr) m_scene->render();
}

// ---------------------------------------------------------------------------------------------------------------------

void SceneController::dispose()
{
    if(m_scene != nullptr) m_scene->dispose();
}

// ---------------------------------------------------------------------------------------------------------------------

}}}