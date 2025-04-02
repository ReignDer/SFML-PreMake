#pragma once
#include "ForceGenerator.h"

namespace Core
{
    class GravityForceGenerator : public ForceGenerator
    {
    private:
        sf::Vector2f gravity = sf::Vector2f(0, 9.8f);
    public:
        GravityForceGenerator(const sf::Vector2f& gravity) : gravity(gravity) {}
        void UpdateForce(Entity* entity, const sf::Time& time) override;
    };
}
