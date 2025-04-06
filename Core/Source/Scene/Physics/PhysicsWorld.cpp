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

    void PhysicsWorld::GenerateContacts()
    {
        
        Contacts.clear();
        
        this->GetOverlaps();
        
    }

    void PhysicsWorld::GetOverlaps()
    {
        if (m_Entities.empty()) {
            return; // Exit early if there are no entities
        }
        for (int i = 0; i < m_Entities.size() - 1; i++) {
            std::list<Entity*>::iterator a = std::next(m_Entities.begin(), i);

            for (int h = i + 1; h < m_Entities.size(); h++) {
                std::list<Entity*>::iterator b = std::next(m_Entities.begin(), h);
                
                ColliderComponent* aBounds = dynamic_cast<ColliderComponent*>((*a)->findComponentByName("Collider"));
                ColliderComponent* bBounds = dynamic_cast<ColliderComponent*>((*b)->findComponentByName("Collider"));
               
                if (!aBounds || !bBounds) continue;
                
               
                sf::FloatRect aBoundsFR = aBounds->getGlobalBounds();
                sf::FloatRect bBoundsFR = bBounds->getGlobalBounds();
                sf::Vector2f mag2Vec = (*a)->m_Position - (*b)->m_Position;
                
                
                float mag2 = (mag2Vec.x * mag2Vec.x) + (mag2Vec.y * mag2Vec.y);
                float magnitude = sqrt(mag2);
                //LOG((*b)->m_Position.y);
                if (!aBoundsFR.intersects(bBoundsFR)) continue;
                //LOG("COllider");
                sf::Vector2f dir = (magnitude != 0) ? sf::Vector2f((mag2Vec.x / magnitude),
                (mag2Vec.y / magnitude)): sf::Vector2f(0, 0);
                
                float overlapX = (aBoundsFR.left + aBoundsFR.width) - bBoundsFR.left;
                float overlapY = (aBoundsFR.top + aBoundsFR.height) - bBoundsFR.top;
                float depth = std::min(overlapX, overlapY);
                
                if (depth <= 0) continue;
                
                

                AddContact(*a, *b, 0.0f, dir, depth);
            }
        }
    }

    void PhysicsWorld::AddContact(Entity* e1, Entity* e2, float restitution, sf::Vector2f contactNormal)
    {
        EntityContact* toAdd = new EntityContact();

        toAdd->entity[0] = e1;
        toAdd->entity[1] = e2;
        toAdd->restitution = restitution;
        toAdd->contactNormal = contactNormal;

        Contacts.push_back(toAdd);
    }

    void PhysicsWorld::AddContact(Entity* e1, Entity* e2, float restitution, sf::Vector2f contactNormal, float depth)
    {
        EntityContact* toAdd = new EntityContact();

        toAdd->entity[0] = e1;
        toAdd->entity[1] = e2;
        toAdd->restitution = restitution;
        toAdd->contactNormal = contactNormal;
        toAdd->depth = depth;

        Contacts.push_back(toAdd);
    }

    void PhysicsWorld::addEntity(Entity* entity)
    {
        
        m_Entities.emplace_back(entity);
        LOG("Added entity");
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

        GenerateContacts();

        if (!Contacts.empty())
        {
            contactResolver.ResolveContacts(Contacts,time);
            
        }
    }
    void PhysicsWorld::deleteAllObjectInScene()
    {
        forceRegistry.Clear();

        m_Entities.clear();
        Contacts.clear();
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
