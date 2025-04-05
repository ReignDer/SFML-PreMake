#include "Corepch.h"
#include "EntityContact.h"

namespace Core
{
    void EntityContact::Resolve(const sf::Time& time)
    {
        ResolveVelocity(time);
        ResolveInterpenetration(time);
    }

    float EntityContact::GetSeparatingSpeed()
    {
        
        sf::Vector2f velocity = entity[0]->m_Velocity;
        if (entity[1]) velocity -= entity[1]->m_Velocity;
        return (velocity.x * contactNormal.x) + (velocity.y * contactNormal.y);
    }

    void EntityContact::ResolveInterpenetration(const sf::Time& time)
    {
        if (depth <= 0) return;
        
        float totalMass = (float)1 / entity[0]->m_Mass;

        if (entity[1]) {
            totalMass += (float)1 / entity[1]->m_Mass;
        }

        if (totalMass <= 0) return;

        float totalMoveByMass = depth / totalMass;
         sf::Vector2f moveByMass = contactNormal * totalMoveByMass;

        if (entity[0]->moveable) {
             sf::Vector2f P_a = moveByMass * ((float)1 / entity[0]->m_Mass);
            entity[1]->m_Position = {0,0};
            entity[1]->m_Velocity = {0,0};
        }

        if (entity[1] && entity[1]->moveable) {
            sf::Vector2f P_b = moveByMass * (-(float)1 / entity[1]->m_Mass);
            entity[1]->m_Position = {0,0};
            entity[1]->m_Velocity = {0,0};
        }
        depth = 0;
    }

    void EntityContact::ResolveVelocity(const sf::Time& time)
    {
        float separatingSpeed = GetSeparatingSpeed();

        if (separatingSpeed > 0)
            return;
        
        float newSS = -restitution * separatingSpeed;
        float deltaSpeed = newSS - separatingSpeed;

        float totalMass = (float)1 / entity[0]->m_Mass;
        if (entity[1]) totalMass += (float)1 / entity[1]->m_Mass;
	
        if (totalMass <= 0) return;

        float impulse_mag = deltaSpeed / totalMass;
        sf::Vector2f Impulse = contactNormal * impulse_mag;

        if (entity[0]->moveable) {
            sf::Vector2f V_a = Impulse * ((float)1 / entity[0]->m_Mass);
            entity[0]->m_Velocity = entity[0]->m_Velocity + V_a;
        }

        if (entity[1] && entity[1]->moveable) {
            sf::Vector2f V_b = Impulse * ((float)-1 / entity[1]->m_Mass);
            entity[1]->m_Velocity = entity[1]->m_Velocity + V_b;
        }
    }
}
