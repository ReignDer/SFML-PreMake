#include "Corepch.h"
#include "ContactResolver.h"

void Core::ContactResolver::ResolveContacts(std::vector<EntityContact*> contacts, const sf::Time& time)
{
    current_iterations = 0;

    while (current_iterations < max_iterations) {
        unsigned current_index = 0;
        float curr_min = contacts[0]->GetSeparatingSpeed();
        float max_depth = contacts[0]->depth;

        for (int i = 0; i < contacts.size(); i++) {

            float ss = contacts[i]->GetSeparatingSpeed();

            if (ss < curr_min && 
                (ss < 0 || contacts[i]->depth)) {
                current_index = i;
                curr_min = ss;

                max_depth = std::max(max_depth, contacts[i]->depth);
            }
        }

        if (curr_min >= 0 && max_depth <= 0) {
            return;
        }

        contacts[current_index]->Resolve(time);
        current_iterations++;

    }
}
