#include "SmallRingMovement.h"

#include "Scripts/Managers/ObjectPoolHolder.h"

SmallRingMovement::SmallRingMovement(const std::string& name) : Core::AbstractComponent(name,Script)
{
    this->reset();
}

void SmallRingMovement::perform()
{
    m_Ticks += timestep.asSeconds();
    m_currentTicks += timestep.asSeconds();
    
    sf::Transformable* transform = getOwner()->getTransformable();

    if (m_Ticks > m_Delay)
    {
        int rnd = rand() % 100;
        if (m_currentTicks >= 180.f && rnd > 90.f)
            transform->move(-timestep.asSeconds() * (SPEED), 0);
        else
            transform->move(-timestep.asSeconds() * (SPEED/2), 0);
    }

    if (transform->getPosition().x < -500)
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

