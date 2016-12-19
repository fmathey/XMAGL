#ifndef _XMAGL_ENTITY_HPP
#define _XMAGL_ENTITY_HPP

#include <XMA/Config.hpp>
#include <XMA/Component.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

class Engine;

using ComponentID = std::size_t;

constexpr std::size_t MaxComponents { 32 };

// ---------------------------------------------------------------------------------------------------------------------

class Entity
{
    friend class Engine;

    public:

        virtual ~Entity();

        bool isAlive() const;
        Entity& destroy();

        Entity& addEntity();


//        bool hasEntity(Entity* entity) const;

//        bool hasParent() const;
//
//        Entity& getParent();
//
//        Entity& getRoot();

        template<typename T> bool hasComponent() const
        { return m_componentBitset[getComponentTypeID<T>()]; }

        template<typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs)
        {
            XMA_ASSERT(!hasComponent<T>());

            T* c(new T(std::forward<TArgs>(mArgs)...));

            c->m_entity = this;
            c->m_engine = &m_engine;

            std::unique_ptr<Component> uPtr{c};
            m_components.emplace_back(std::move(uPtr));
            m_componentArray[getComponentTypeID<T>()] = c;
            m_componentBitset[getComponentTypeID<T>()] = true;

            c->create();

            return *c;
        };

        template<typename T> T& getComponent() const
        {
            XMA_ASSERT(hasComponent<T>());
            auto ptr(m_componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

    private:

        Entity(Engine& engine, Entity* parent = nullptr);

        Entity& update(float deltaTime);

        inline std::size_t getUniqueComponentID() const noexcept
        {
            static ComponentID lastID{0u};
            return lastID++;
        }

        template <typename T> inline ComponentID getComponentTypeID() const noexcept
        {
            XMA_ASSERT_STATIC_CLASS(Component, T);
            static ComponentID typeID{getUniqueComponentID()};
            return typeID;
        };

    private:

        Entity* m_parent { nullptr };

        Engine& m_engine;

        bool m_isAlive { true };

        std::vector<std::unique_ptr<Component>> m_components;
        std::array<Component*, MaxComponents> m_componentArray;
        std::bitset<MaxComponents> m_componentBitset;

        std::vector<std::unique_ptr<Entity>> m_entities;

};

// ---------------------------------------------------------------------------------------------------------------------

}

#endif
