#include "BigRingMovement.h"

#include "Scripts/Managers/ObjectPoolHolder.h"

BigRingMovement::BigRingMovement(const std::string& name) : Core::AbstractComponent(name,Script)
{
    this->reset();
}

void BigRingMovement::perform()
{
    m_Ticks += timestep.asSeconds();
    
    sf::Transformable* transform = getOwner()->getTransformable();

    if (m_Ticks > m_Delay)
    {
        transform->move(-timestep.asSeconds() * (SPEED/2), 0);
    }

    if (transform->getPosition().x < -450)
    {
        ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BIGRING_POOL_TAG)->releasePoolable((EntityPoolable*)this->getOwner());
    }

    
}

void BigRingMovement::configure(float delay)
{
    m_Delay = delay;
}

void BigRingMovement::reset()
{
    m_Ticks = 0.0f;
}
