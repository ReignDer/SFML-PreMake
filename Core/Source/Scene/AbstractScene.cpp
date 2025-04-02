#include "Corepch.h"
#include "AbstractScene.h"

#include "Physics/PhysicsWorld.h"

namespace Core {
	AbstractScene::AbstractScene(const std::string& name)
	{
		this->name = name;
	}

	void AbstractScene::OnUnloadObjects()
	{
		EntityManager::getInstance()->deleteAllObjectInScene();
		PhysicsWorld::getInstance()->deleteAllObjectInScene();
	}

	void AbstractScene::registerEntity(Entity* entity)
	{
		EntityManager::getInstance()->addEntity(entity);
		
	}
}
