#include "BigRingAnimation.h"

#include "Scripts/Entity/Entities/BigRing.h"

BigRingAnimation::BigRingAnimation(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void BigRingAnimation::perform()
{
    auto atlas = static_cast<BigRing*>(getOwner());
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

void BigRingAnimation::reset()
{
    m_Ticks = 0.0f;
}
