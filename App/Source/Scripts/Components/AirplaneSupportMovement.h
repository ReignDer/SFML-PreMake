#pragma once
#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/Entities/Player.h"
#include "Scripts/Poolables/EntityPool.h"
#include "Scripts/Components/PlayerInputController.h"
#include "Scripts/Managers/ObjectPoolHolder.h"
class AirplaneSupportMovement : public Core::AbstractComponent
{
public:
	AirplaneSupportMovement(std::string name);
	virtual void perform() override;
private:
	const float SPEED = 300.f;
	const float BULLET_SPAWN_INTERVAL = 2.0f;
	float m_Ticks = 0.0f;

	EntityPool* m_ProjectilePool = nullptr;
};

