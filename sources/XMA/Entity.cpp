#include <XMA/Entity.hpp>
#include <XMA/Components/RenderableComponent.hpp>

namespace XMA {

// ---------------------------------------------------------------------------------------------------------------------

Entity::Entity(Engine& engine, Entity* parent) : m_engine(engine), m_parent(parent)
{}

// ---------------------------------------------------------------------------------------------------------------------

Entity::~Entity()
{
    std::reverse(m_entities.begin(), m_entities.end());
    for(auto& e : m_entities) e.reset();
}

// ---------------------------------------------------------------------------------------------------------------------

bool Entity::isAlive() const
{
    return m_isAlive;
}

// ---------------------------------------------------------------------------------------------------------------------

Entity& Entity::destroy()
{
    m_isAlive = false;
    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

Entity& Entity::addEntity()
{
    Entity* e { new Entity(m_engine, this) };
    std::unique_ptr<Entity> uPtr { e };
    m_entities.emplace_back(std::move(uPtr));
    return *e;
}

// ---------------------------------------------------------------------------------------------------------------------

//bool Entity::hasEntity(Entity* entity) const
//{
//    if(entity == nullptr || (entity != nullptr && !entity->isAlive())) return false;
//
//    auto it(std::find_if(m_entities.begin(), m_entities.end(),
//                         [=](const std::unique_ptr<Entity>& object) {
//                             return object.get() == entity;
//                         }));
//
//    return it != m_entities.end();
//}

// ---------------------------------------------------------------------------------------------------------------------

Entity& Entity::update(float deltaTime)
{
    m_entities.erase(
            std::remove_if(std::begin(m_entities), std::end(m_entities),
                           [](const std::unique_ptr<Entity>& entity) {
                               return !entity->isAlive();
                           }),
            std::end(m_entities)
    );

    for(auto& c : m_components) c->update(deltaTime);

    for(auto& e : m_entities) e->update(deltaTime);

    return *this;
}

// ---------------------------------------------------------------------------------------------------------------------

//bool Entity::hasParent() const
//{
//    return m_parent != nullptr;
//}

// ---------------------------------------------------------------------------------------------------------------------

//Entity& Entity::getParent()
//{
//    if(m_parent != nullptr) return *m_parent;
//    return getRoot();
//}

// ---------------------------------------------------------------------------------------------------------------------

//Entity& Entity::getRoot()
//{
//    XMA_ASSERT(m_root != nullptr);
//    return *m_root;
//}

// ---------------------------------------------------------------------------------------------------------------------

}