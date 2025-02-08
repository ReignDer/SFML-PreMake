#pragma once
#include "Builder.h"
#include "SFML/Graphics.hpp"
#include "Scripts/Poolables/EntityPool.h"

typedef std::unordered_map<std::string, EntityPool*> PoolMap;

class ObjectPoolHolder : private sf::NonCopyable
{
public:
	static const std::string ENEMY_POOL_TAG;
	static ObjectPoolHolder* getInstance();

	void registerObjectPool(EntityPool* pool);
	void unregisterObjectPool(EntityPool* pool);

	EntityPool* getPool(const std::string& tag) { return poolMap[tag]; }
private:
	ObjectPoolHolder();
	static ObjectPoolHolder* sharedInstance;
	PoolMap poolMap;
};

