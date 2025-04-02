#include "Corepch.h"
#include "GravityForceGenerator.h"


namespace Core
{
    void GravityForceGenerator::UpdateForce(Entity* entity, const sf::Time& time)
    {
        if (entity->m_Mass <= 0.f) return;
        sf::Vector2f force = gravity * entity->m_Mass;
        
        entity->addForce(force);
    }
}
