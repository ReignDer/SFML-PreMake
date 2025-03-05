#pragma once

#include "Scene/Entity.h"
#include "Scene/Component.h"
#include "CollisionListener.h"

namespace Core {
	class ColliderComponent : public AbstractComponent {
	public:
		ColliderComponent(const std::string& name);

		void setCollisionListener(CollisionListener* listener);

		bool willCollide(ColliderComponent* another);
		bool hasCollisionWith(ColliderComponent* collider);
		void addCollision(ColliderComponent* collider);
		void removeCollision(ColliderComponent* collider);

		sf::FloatRect getGlobalBounds();
		void setLocalBounds(sf::FloatRect localBounds);
		void collisionEnter(Entity* entity);
		void collisionExit(Entity* entity);

		void perform();
		void clearCollisions();

	private:
		
		bool m_Checked = false;

		std::unordered_set<ColliderComponent*> m_Collisions;
		sf::FloatRect m_LocalBounds;
		CollisionListener* m_Listener;
	};
}

