#include "Corepch.h"
#include "PhysicsManager.h"


namespace Core {

	PhysicsManager* PhysicsManager::sharedInstance = nullptr;

	void PhysicsManager::initialize(const std::string& name, Entity* parent)
	{
		sharedInstance = new PhysicsManager(name);
		parent->attachComponent(sharedInstance);
		
	}

	PhysicsManager* PhysicsManager::getInstance()
	{

		return sharedInstance;
	}


	void PhysicsManager::trackObject(ColliderComponent* object)
	{
		m_TrackedObjects.emplace_back(object);
	}

	void PhysicsManager::untrackObject(ColliderComponent* object)
	{
		m_ForCleaningObjects.emplace_back(object);
	}
	

	void PhysicsManager::perform()
	{
		for (int i = 0; i < m_TrackedObjects.size(); i++) {
			for (int j = i + 1; j < m_TrackedObjects.size(); j++) {
				if (m_TrackedObjects[i]->getOwner()->isEnabled() &&
					m_TrackedObjects[j]->getOwner()->isEnabled()) {

					if (m_TrackedObjects[i]->willCollide(m_TrackedObjects[j])) {
						if (!m_TrackedObjects[i]->hasCollisionWith(m_TrackedObjects[j])) {
							m_TrackedObjects[i]->addCollision(m_TrackedObjects[j]);
							m_TrackedObjects[i]->collisionEnter(m_TrackedObjects[j]->getOwner());
						}

						if (!m_TrackedObjects[j]->hasCollisionWith(m_TrackedObjects[i])) {
							m_TrackedObjects[j]->addCollision(m_TrackedObjects[i]);
							m_TrackedObjects[j]->collisionEnter(m_TrackedObjects[i]->getOwner());
						}
					}
					else {
						if (m_TrackedObjects[i]->hasCollisionWith(m_TrackedObjects[j])) {
							m_TrackedObjects[i]->collisionExit(m_TrackedObjects[j]->getOwner());
							m_TrackedObjects[i]->removeCollision(m_TrackedObjects[j]);
						}
						if (m_TrackedObjects[j]->hasCollisionWith(m_TrackedObjects[i])) {
							m_TrackedObjects[j]->collisionExit(m_TrackedObjects[i]->getOwner());
							m_TrackedObjects[j]->removeCollision(m_TrackedObjects[i]);
						}
					}
					}
			}
		}
		cleanUpObjects();

	}
	

	void PhysicsManager::cleanUpObjects()
	{
		for (int i = 0; i < m_ForCleaningObjects.size(); i++) {
			for (int j = 0; j < m_TrackedObjects.size(); j++) {
				if (m_ForCleaningObjects[i] == m_TrackedObjects[j]) {
					m_TrackedObjects.erase(m_TrackedObjects.begin() + j);
				}
			}
		}
		m_ForCleaningObjects.clear();
	}
}
