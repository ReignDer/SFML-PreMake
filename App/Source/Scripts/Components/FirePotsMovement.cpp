#include "FirePotsMovement.h"

#include "Scripts/Managers/ObjectPoolHolder.h"

FirePotsMovement::FirePotsMovement(const std::string& name) : Core::AbstractComponent(name,Script)
{
    this->reset();
}

void FirePotsMovement::perform()
{
    m_Ticks += timestep.asSeconds();
    m_currentTicks += timestep.asSeconds();
    sf::Transformable* transform = getOwner()->getTransformable();

    if (m_Ticks > m_Delay)
    {
        transform->move(-timestep.asSeconds() * (SPEED/2), 0);
    }

    if (transform->getPosition().x < -500)
    {
        ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FIREPOT_POOL_TAG)->releasePoolable((EntityPoolable*)this->getOwner());
    }

    
}

void FirePotsMovement::configure(float delay)
{
    m_Delay = delay;
}

void FirePotsMovement::reset()
{
    m_Ticks = 0.0f;
}
