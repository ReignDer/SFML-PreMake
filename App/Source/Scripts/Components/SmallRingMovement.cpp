#include "SmallRingMovement.h"

#include "Scripts/Managers/ObjectPoolHolder.h"

SmallRingMovement::SmallRingMovement(const std::string& name) : Core::AbstractComponent(name,Script)
{
    this->reset();
}

void SmallRingMovement::perform()
{
    m_Ticks += timestep.asSeconds();
    
    sf::Transformable* transform = getOwner()->getTransformable();

    if (m_Ticks > m_Delay)
    {
        transform->move(-timestep.asSeconds() * (SPEED/2), 0);
    }

    if (transform->getPosition().x < -450)
    {
        ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::SMALLRING_POOL_TAG)->releasePoolable((EntityPoolable*)this->getOwner());
    }
    
}

void SmallRingMovement::configure(float delay)
{
    m_Delay = delay;
}

void SmallRingMovement::reset()
{
    m_Ticks = 0.0f;
}

