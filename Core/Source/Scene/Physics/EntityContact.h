#pragma once
#include "Scene/Entity.h"

namespace Core
{
    class EntityContact
    {
    public:
        float depth;

        Entity* entity[2];
        float restitution;
        sf::Vector2f contactNormal;
        void Resolve(const sf::Time& time);
        float GetSeparatingSpeed();


    protected:
        void ResolveInterpenetration(const sf::Time& time);
        void ResolveVelocity(const sf::Time& time);
    };
}
