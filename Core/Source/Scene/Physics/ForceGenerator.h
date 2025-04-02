#pragma once
#include "Scene/Entity.h"


namespace Core{
class ForceGenerator
{
public:
    virtual ~ForceGenerator() = default;
    virtual void UpdateForce(Entity* entity, const sf::Time& time)
    {
        entity->addForce(sf::Vector2f(0,0));
    }
};
}
