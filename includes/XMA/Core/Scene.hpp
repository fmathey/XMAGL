#ifndef _XMAGL_CORE_SCENE_HPP
#define _XMAGL_CORE_SCENE_HPP

#include <XMA/Core/Controller.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Scene : public Controller
{};

// ---------------------------------------------------------------------------------------------------------------------

using SceneUptr = std::unique_ptr<Scene>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif