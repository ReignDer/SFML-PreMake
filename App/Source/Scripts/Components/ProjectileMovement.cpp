#include "ProjectileMovement.h"

ProjectileMovement::ProjectileMovement(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void ProjectileMovement::perform()
{
	sf::Transformable* transform = getOwner()->getTransformable();
	transform->move(0, -timestep.asSeconds() * SPEED_MULTIPLIER);
	m_Ticks += timestep.asSeconds();

	if (m_Ticks >= 3.0f) {
		reset();
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG)->releasePoolable((EntityPoolable*)getOwner());
	}
}

void ProjectileMovement::reset()
{
	m_Ticks = 0.f;
}
