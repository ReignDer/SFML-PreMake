#pragma once
#include "ContactResolver.h"
#include "ForceRegistry.h"
#include "GravityForceGenerator.h"
#include "Scene/Entity.h"


namespace Core
{
    class PhysicsWorld : sf::NonCopyable
    {
    protected:
        ContactResolver contactResolver = ContactResolver(20);
        void GenerateContacts();
        void GetOverlaps();
    public:
        static PhysicsWorld* getInstance();
        std::list<Entity*> m_Entities;
        void addEntity(Entity* entity);
        void UpdateEntities(const sf::Time& time);
        void deleteAllObjectInScene();
        void SetGravity(float gravity);
        void UpdateEntityList();
        
        std::vector<EntityContact*> Contacts;
        void AddContact(Entity* e1, Entity* e2, float restitution, sf::Vector2f contactNormal);
        void AddContact(Entity* e1, Entity* e2, float restitution, sf::Vector2f contactNormal, float depth);
    

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
