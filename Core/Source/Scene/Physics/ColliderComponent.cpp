#include "Corepch.h"
#include "ColliderComponent.h"

namespace Core {
	//Collision Component
	ColliderComponent::ColliderComponent(const std::string& name) : AbstractComponent(name, Physics)
	{
	}
	void ColliderComponent::setCollisionListener(CollisionListener* listener)
	{
		m_Listener = listener;
	}

	bool ColliderComponent::willCollide(ColliderComponent* another)
	{
		sf::FloatRect A = this->getGlobalBounds();
		sf::FloatRect B = another->getGlobalBounds();

		return A.intersects(B);
	}
	bool ColliderComponent::hasCollisionWith(ColliderComponent* collider)
	{
		return m_Collisions.find(collider) != m_Collisions.end();
	}
	void ColliderComponent::addCollision(ColliderComponent* collider)
	{
		m_Collisions.insert(collider);
	}
	void ColliderComponent::removeCollision(ColliderComponent* collider)
	{
		m_Collisions.erase(collider);
	}

	sf::FloatRect ColliderComponent::getGlobalBounds()
	{
		return this->getOwner()->getGlobalTransform().transformRect(m_LocalBounds);
	}

	void ColliderComponent::setLocalBounds(sf::FloatRect localBounds)
	{
		m_LocalBounds = localBounds;
	}
	void ColliderComponent::collisionEnter(Entity* entity)
	{
		if (m_Listener != nullptr) {
			m_Listener->OnCollisionEnter(entity);
		}
	}
	void ColliderComponent::collisionExit(Entity* entity)
	{
		if (m_Listener != nullptr) {
			m_Listener->OnCollisionExit(entity);
		}
	}
	void ColliderComponent::perform()
	{
	}
	void ColliderComponent::clearCollisions()
	{
		for (auto& collider : m_Collisions) {
			collider->collisionExit(getOwner());
			collisionExit(getOwner());
			collider->removeCollision(this);
		}
		m_Collisions.clear();
	}
}