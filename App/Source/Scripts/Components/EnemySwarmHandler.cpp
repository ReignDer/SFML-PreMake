#include "EnemySwarmHandler.h"

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, const std::string& name, Core::Entity* parent) 
	: Core::AbstractComponent(name, Script)
{
	enemyPool = new EntityPool(ObjectPoolHolder::ENEMY_POOL_TAG, new EnemyAirplane("enemy"), numEnemies, parent);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete enemyPool;
}

void EnemySwarmHandler::perform()
{
	auto enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ticks += timestep.asSeconds();

	if (ticks > SPAWN_INTERVAL) {
		ticks = 0.0f;
		enemyPool->requestPoolable();
	}
}
