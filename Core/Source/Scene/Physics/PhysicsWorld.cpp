#include "Corepch.h"
#include "PhysicsWorld.h"

#include "PhysicsManager.h"

namespace Core
{
    PhysicsWorld* PhysicsWorld::sharedInstance = nullptr;

    PhysicsWorld* PhysicsWorld::getInstance()
    {
        if (sharedInstance == nullptr) {
            sharedInstance = new PhysicsWorld();
        }
        return sharedInstance;

    }

    void PhysicsWorld::addEntity(Entity* entity)
    {
        m_Entities.emplace_back(entity);

        if (entity->hasGravity)
        {
            forceRegistry.Add(entity, &m_Gravity);
        }
    }

    void PhysicsWorld::UpdateEntities(const sf::Time& time)
    {
        UpdateEntityList();
        forceRegistry.UpdateForce(time);

        for (auto& entity : m_Entities)
        {
            entity->update(time);
        }
    }
    void PhysicsWorld::deleteAllObjectInScene()
    {
        forceRegistry.Clear();

        m_Entities.clear();
    }
    void PhysicsWorld::UpdateEntityList()
    {
        m_Entities.remove_if(
        [](const Entity* p) {
            return p == nullptr;
        }
    );
    }

}
