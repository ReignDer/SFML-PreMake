#include "ObstacleHandler.h"

#include "Scripts/Entity/Entities/BigRing.h"
#include "Scripts/Entity/Entities/FirePots.h"
#include "Scripts/Entity/Entities/SmallRing.h"
#include "Scripts/Managers/ObjectPoolHolder.h"

ObstacleHandler::ObstacleHandler(const std::string& name, int numberObstacles, Core::Entity* parent) : Core::AbstractComponent(name, Script)
{
    bigRingPool = new EntityPool(ObjectPoolHolder::BIGRING_POOL_TAG,new BigRing("BigRings"),numberObstacles, parent);
    bigRingPool->initialize();
    smallRingPool = new EntityPool(ObjectPoolHolder::SMALLRING_POOL_TAG,new SmallRing("SmallRings"),numberObstacles, parent);
    smallRingPool->initialize();
    firePotPool = new EntityPool(ObjectPoolHolder::FIREPOT_POOL_TAG,new FirePots("FirePots"),numberObstacles, parent);
    firePotPool->initialize();

    ObjectPoolHolder::getInstance()->registerObjectPool(smallRingPool);
    ObjectPoolHolder::getInstance()->registerObjectPool(bigRingPool);
    ObjectPoolHolder::getInstance()->registerObjectPool(firePotPool);
}

ObstacleHandler::~ObstacleHandler()
{
    delete bigRingPool;
    delete smallRingPool;
    delete firePotPool;
}

void ObstacleHandler::perform()
{
    auto bigPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BIGRING_POOL_TAG);
    auto smallPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::SMALLRING_POOL_TAG);
    auto firePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FIREPOT_POOL_TAG);
    ticks += timestep.asSeconds();
    
    if (ticks > SPAWN_INTERVAL) {
        ticks = 0.0f;
        bigPool->requestPoolable();
        smallPool->requestPoolable();
        firePool->requestPoolable();
    }
}
