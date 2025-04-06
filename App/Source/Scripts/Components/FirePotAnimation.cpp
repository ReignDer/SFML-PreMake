#include "FirePotAnimation.h"

#include "Scripts/Entity/Entities/FirePots.h"

FirePotAnimation::FirePotAnimation(const std::string& name) : Core::AbstractComponent(name,Script)
{
}

void FirePotAnimation::perform()
{
    auto atlas = static_cast<FirePots*>(getOwner());
    auto values = atlas->getValues();
    m_Ticks += timestep.asSeconds();

    if (m_Ticks > 0.3f) {
        reset();
        currentIndex++;
        if (currentIndex > values.size() - 1) {
            currentIndex = 0;
        }
        atlas->setSprite(values[currentIndex]);
    }

    
}

void FirePotAnimation::reset()
{
    m_Ticks = 0.0f;
}
