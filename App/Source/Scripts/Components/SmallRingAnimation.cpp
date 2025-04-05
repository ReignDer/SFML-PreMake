#include "SmallRingAnimation.h"

#include "Scripts/Entity/Entities/SmallRing.h"

SmallRingAnimation::SmallRingAnimation(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void SmallRingAnimation::perform()
{
    auto atlas = static_cast<SmallRing*>(getOwner());
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

void SmallRingAnimation::reset()
{
    m_Ticks = 0.0f;
}
