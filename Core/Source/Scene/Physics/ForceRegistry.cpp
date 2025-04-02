#include "Corepch.h"
#include "ForceRegistry.h"

namespace Core
{
    void ForceRegistry::Add(Entity* entity, ForceGenerator* force)
    {
        EntityForceRegistry toAdd;
        toAdd.entity = entity;
        toAdd.generator = force;

        Registry.emplace_back(toAdd);
    }

    void ForceRegistry::Remove(Entity* entity, ForceGenerator* force)
    {
        Registry.remove_if([entity,force](EntityForceRegistry reg)
        {
            return reg.entity == entity && reg.generator == force;
        });
    }

    void ForceRegistry::Clear()
    {
        Registry.clear();
    }

    void ForceRegistry::UpdateForce(const sf::Time& time) const
    {
        for (auto& it : Registry) it.generator->UpdateForce(it.entity, time);
    }
}
