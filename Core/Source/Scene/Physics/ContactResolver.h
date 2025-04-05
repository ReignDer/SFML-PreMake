#pragma once
#include "EntityContact.h"

namespace Core
{
    class ContactResolver
    {
    protected:
        unsigned current_iterations = 0;
    public:
        unsigned max_iterations;
        ContactResolver(unsigned _maxIterations) : max_iterations(_maxIterations) {}
        void ResolveContacts(std::vector<EntityContact*> contacts, const sf::Time& time);
    };
}
