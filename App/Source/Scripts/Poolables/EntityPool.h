#pragma once
#include "Builder.h"
#include "EntityPoolable.h"

class EntityPool
{
public:
	EntityPool(const std::string& tag, EntityPoolable* poolable, int poolableSize, Core::Entity* parent);
	virtual ~EntityPool();
	void initialize();

	bool hasObjectAvailable(int requestSize);

	EntityPoolable* requestPoolable();
	std::vector<EntityPoolable*> requestPoolableBatch(int size);

	void releasePoolable(EntityPoolable* poolableObject);
	void releasePoolableBatch(std::vector<EntityPoolable*> objectList);

	std::string getTag() { return tag; }

private:
	std::string tag;
	EntityPoolable* objectCopy = nullptr;
	Core::Entity* parent = nullptr;

	int maxPoolSize = 0;

	std::vector <EntityPoolable*> availableObjects;
	std::vector<EntityPoolable*> usedObjects;

	void setEnabled(EntityPoolable* poolableObject, bool flag);
};

