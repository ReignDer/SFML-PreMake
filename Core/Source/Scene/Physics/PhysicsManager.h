#pragma once

#include "Scene/Component.h"
#include "Scene/Entity.h"
#include "Scene/Physics/ColliderComponent.h"

namespace Core {
	typedef std::vector<ColliderComponent*> CollisionList;
	class PhysicsManager : public AbstractComponent
	{
	private:
		CollisionList m_TrackedObjects;
		CollisionList m_ForCleaningObjects;
	public:
		static void initialize(const std::string& name, Entity* parent);
		static PhysicsManager* getInstance();

		void trackObject(ColliderComponent* object);
		void untrackObject(ColliderComponent* object);
		
		void perform();
	private:
		PhysicsManager(const std::string& name) : AbstractComponent(name, Script) {};
		PhysicsManager(PhysicsManager const&) : AbstractComponent(name, Script) {};
		PhysicsManager& operator=(PhysicsManager const&){};
		static PhysicsManager* sharedInstance;
		bool m_EnableGravity = false;
		

		void cleanUpObjects();
	};
}

