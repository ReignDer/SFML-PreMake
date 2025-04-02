#pragma once
#include "ForceGenerator.h"
#include "Core/Core.h"

namespace Core
{
    class ForceRegistry
    {
    public:
        void Add(Entity* entity, ForceGenerator* force);
        void Remove(Entity* entity, ForceGenerator* force);
        void Clear();
        void UpdateForce(const sf::Time& time) const;

    protected:

        struct EntityForceRegistry {
            Entity* entity;
            ForceGenerator* generator;
        };

        std::list<EntityForceRegistry> Registry;
    };
};
