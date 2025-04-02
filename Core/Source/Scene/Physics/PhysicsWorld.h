#pragma once
#include "ForceRegistry.h"
#include "GravityForceGenerator.h"
#include "Scene/Entity.h"


namespace Core
{
    class PhysicsWorld : sf::NonCopyable
    {
    public:
        static PhysicsWorld* getInstance();
        std::list<Entity*> m_Entities;
        void addEntity(Entity* entity);
        void UpdateEntities(const sf::Time& time);
        void deleteAllObjectInScene();
        void SetGravity(float gravity);
        void UpdateEntityList();

    public:
        ForceRegistry forceRegistry;

    private:
        GravityForceGenerator m_Gravity = GravityForceGenerator(sf::Vector2f(0,9.8f));
        static PhysicsWorld* sharedInstance;
       
    };

    inline void PhysicsWorld::SetGravity(float gravity)
    {
        m_Gravity = GravityForceGenerator(sf::Vector2f(0,gravity));
    }
}
