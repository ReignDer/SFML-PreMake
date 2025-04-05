#include "ObjectPoolHolder.h"

const std::string ObjectPoolHolder::ENEMY_POOL_TAG = "EnemyPool";
const std::string ObjectPoolHolder::PROJECTILE_POOL_TAG = "ProjectilePool";
const std::string ObjectPoolHolder::BIGRING_POOL_TAG = "BigRingPool";
const std::string ObjectPoolHolder::SMALLRING_POOL_TAG = "SmallRingPool";
const std::string ObjectPoolHolder::FIREPOT_POOL_TAG = "FirePotPool";

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
