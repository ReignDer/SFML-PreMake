#pragma once
#include "Builder.h"
#include "Scripts/Poolables/EntityPool.h"

class ObstacleHandler : public Core::AbstractComponent
{
public:
    ObstacleHandler(const std::string& name, int numberObstacles, Core::Entity* parent);
    virtual ~ObstacleHandler();
    virtual void perform() override;

private:
    EntityPool* bigRingPool;
    EntityPool* smallRingPool;
    EntityPool* firePotPool;
    const float SPAWN_INTERVAL = 0.01f;
    float ticks = 0.0f;
    
};
