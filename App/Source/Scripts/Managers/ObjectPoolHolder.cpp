#include "ObjectPoolHolder.h"

const std::string ObjectPoolHolder::ENEMY_POOL_TAG = "EnemyPool";
const std::string ObjectPoolHolder::PROJECTILE_POOL_TAG = "ProjectilePool";

ObjectPoolHolder* ObjectPoolHolder::sharedInstance = nullptr;


ObjectPoolHolder* ObjectPoolHolder::getInstance()
{
	if (sharedInstance == nullptr) {
		sharedInstance = new ObjectPoolHolder();
	}

	return sharedInstance;
}

void ObjectPoolHolder::registerObjectPool(EntityPool* pool)
{
	poolMap[pool->getTag()] = pool;
}

void ObjectPoolHolder::unregisterObjectPool(EntityPool* pool)
{
	poolMap.erase(pool->getTag());

}

ObjectPoolHolder::ObjectPoolHolder()
{
}
