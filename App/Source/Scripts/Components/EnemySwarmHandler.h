#pragma once
#include "Builder.h"
#include "Scripts/Poolables/EntityPool.h"
#include "Scripts/Managers/ObjectPoolHolder.h"
#include "Scripts/Entity/Entities/EnemyAirplane.h"
class EnemySwarmHandler : public Core::AbstractComponent
{
public:
	EnemySwarmHandler(int numEnemies, const std::string& name, Core::Entity* parent);
	virtual ~EnemySwarmHandler();
	virtual void perform() override;
private:
	EntityPool* enemyPool;
	const float SPAWN_INTERVAL = 0.01f;
	float ticks = 0.0f;
};

