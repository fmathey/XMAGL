#ifndef _XMAGL_CORE_CONTROLLERLIST_HPP
#define _XMAGL_CORE_CONTROLLERLIST_HPP

#include <XMA/Core/Controller.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

class Engine;

using ControllerID = std::size_t;

constexpr std::size_t MaxControllers { 32 };

// ---------------------------------------------------------------------------------------------------------------------

class ControllerList
{
    public:

        ControllerList(Engine& engine) : m_engine(engine)
        {}

        template<typename T, typename... TArgs>
        T& add(TArgs&&... mArgs)
        {
            static_assert(std::is_base_of<Controller, T>::value, "T must inherit from Controller");
            if(has<T>()) XMA_THROW("Duplicated controller");
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->setEngine(m_engine);
            c->create();
            std::unique_ptr<Controller> uPtr{c};
            m_controllerArray[getControllerTypeID<T>()] = c;
            m_controllerBitset[getControllerTypeID<T>()] = true;
            m_controllers.emplace_back(std::move(uPtr));
            return *c;
        };

        template<typename T> bool has() const
        { return m_controllerBitset[getControllerTypeID<T>()]; }

        template<typename T> T& get() const
        {
            XMA_ASSERT(has<T>())
            auto ptr(m_controllerArray[getControllerTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

        template<typename T> ControllerList& remove()
        {
            if(has<T>()) {
                get<T>().dispose();

                m_controllerBitset[getControllerTypeID<T>()] = false;
                m_controllerArray[getControllerTypeID<T>()] = nullptr;

                m_controllers.erase(
                        std::remove_if(
                                m_controllers.begin(),
                                m_controllers.end(),
                                [&] (std::unique_ptr<Controller> const& c) {
                                    return std::find(
                                            m_controllerArray.cbegin(),
                                            m_controllerArray.cend(),
                                            c.get()
                                    ) == m_controllerArray.end();
                                }),
                        m_controllers.end()
                );
            }
            return *this;
        }

        ControllerList& create() { for(auto& c : m_controllers) { c->create(); } return *this; }
        ControllerList& update(float deltaTime) { for(auto& c : m_controllers) { c->update(deltaTime); } return *this; }
        ControllerList& render() { for(auto& c : m_controllers) { c->render(); } return *this; }
        ControllerList& dispose() {
            std::reverse(m_controllers.begin(), m_controllers.end());
            for(auto& c : m_controllers) { c->dispose(); } return *this;
        }

    private:

        inline std::size_t getUniqueControllerID() const noexcept
        {
            static ControllerID lastID{0u};
            return lastID++;
        }

        template <typename T> inline ControllerID getControllerTypeID() const noexcept
        {
            static_assert(std::is_base_of<Controller, T>::value, "T must inherit from Controller");
            static ControllerID typeID{getUniqueControllerID()};
            return typeID;
        };

        std::vector<std::unique_ptr<Controller>> m_controllers;
        std::array<Controller*, MaxControllers> m_controllerArray;
        std::bitset<MaxControllers> m_controllerBitset;

        Engine& m_engine;
};

// ---------------------------------------------------------------------------------------------------------------------

using ControllerListUptr = std::unique_ptr<ControllerList>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
