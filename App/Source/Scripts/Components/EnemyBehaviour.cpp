#include "EnemyBehaviour.h"

EnemyBehaviour::EnemyBehaviour(const std::string& name) : AbstractComponent(name, Script)
{
	this->reset();
	

}

EnemyBehaviour::~EnemyBehaviour()
{

}

void EnemyBehaviour::perform()
{

	//LOG(duration);
	m_Ticks += timestep.asSeconds();


	sf::Transformable* transform = getOwner()->getTransformable();



	if (m_Ticks > ((rand() % 3) + 1.0f) && m_MovementType != Side) {
		int counter = (m_MovementType + 1) % (EnemyMovementType::Side + 1);
		m_MovementType = (EnemyMovementType)counter;
	}

	if (m_MovementType == EnemyBehaviour::Forward)
		transform->move(0, timestep.asSeconds() * SPEED);
	else if (m_MovementType == EnemyBehaviour::SlowForward)
		transform->move(0, timestep.asSeconds() * (SPEED / 2.f));

	else if (m_MovementType == EnemyBehaviour::Side) {

		if (transform->getPosition().x > Core::Core::Get().GetWindow().GetWidth() / 2)
			transform->move(timestep.asSeconds() * SPEED * 1.5, 0);
		else
			transform->move(-timestep.asSeconds() * SPEED * 1.5, 0);

		if (transform->getPosition().x > Core::Core::Get().GetWindow().GetWidth() + 20 ||
			transform->getPosition().x < -20) {
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((EntityPoolable*)this->getOwner());
		}
	}

}

void EnemyBehaviour::configure(float delay)
{
	m_Delay = delay;
}

void EnemyBehaviour::reset()
{
	m_Ticks = 0.0f;
	m_MovementType = Forward;

	duration = (rand() % 3) + 1.0f;
}
