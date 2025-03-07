#include "EntityPool.h"

EntityPool::EntityPool(const std::string& tag, EntityPoolable* poolable, int poolableSize, Core::Entity* parent) :
	tag(tag),objectCopy(poolable),maxPoolSize(poolableSize),parent(parent)
{
}

EntityPool::~EntityPool()
{
	LOG("DELETED POOLERS");
	delete objectCopy;
	objectCopy = nullptr;
	parent = nullptr;

}

void EntityPool::initialize()
{
	for (int i = 0; i < maxPoolSize; i++) {
		EntityPoolable* poolable = objectCopy->clone();

		if (parent != nullptr) {
			parent->attachChild(poolable);
		}
		else
			Core::EntityManager::getInstance()->addEntity(poolable);

		poolable->setEnabled(false);
		//LOG("ADDED POOLABLE");
		availableObjects.emplace_back(poolable);
	}
}

bool EntityPool::hasObjectAvailable(int requestSize)
{
	return requestSize <= availableObjects.size();
}

EntityPoolable* EntityPool::requestPoolable()
{
	if (hasObjectAvailable(1)) {
		EntityPoolable* poolable = availableObjects.back();
		availableObjects.erase(availableObjects.begin() + (availableObjects.size() - 1));
		usedObjects.emplace_back(poolable);

		setEnabled(poolable, true);
		//LOG("POOLABLE REQUESTED");
		return poolable;
		
	}
	else
		return nullptr;
}

std::vector<EntityPoolable*> EntityPool::requestPoolableBatch(int size)
{
	std::vector<EntityPoolable*> returnList;
	if (hasObjectAvailable(size)) {
		for (int i = 0; i < size; i++) {
			returnList.emplace_back(requestPoolable());
		}
	}
	else
		LOG("No Sufficient poolables");

	return returnList;
}

void EntityPool::releasePoolable(EntityPoolable* poolableObject)
{
	for (int i = 0; i < usedObjects.size(); i++) {
		if (usedObjects[i] == poolableObject) {
			usedObjects.erase(usedObjects.begin() + i);
			availableObjects.emplace_back(poolableObject);
			setEnabled(poolableObject, false);
			//LOG("POOLABLE RELEASED");
		}
	}
}

void EntityPool::releasePoolableBatch(std::vector<EntityPoolable*> objectList)
{
	for (auto& poolableObject : objectList) {
		releasePoolable(poolableObject);
	}
}

void EntityPool::setEnabled(EntityPoolable* poolableObject, bool flag)
{
	if (flag) {
		poolableObject->setEnabled(true);
		poolableObject->OnActivate();
	}
	else {
		poolableObject->setEnabled(false);
		poolableObject->OnRelease();
	}
}
