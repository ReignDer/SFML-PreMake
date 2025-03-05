#pragma once
#include "Builder.h"
#include "Scripts/Managers/ObjectPoolHolder.h"
class ProjectileMovement : public Core::AbstractComponent
{
public:
	ProjectileMovement(const std::string& name);
	virtual void perform() override;
	void reset();

private:
	const float SPEED_MULTIPLIER = 240.0f;
	float m_Ticks = 0.f;
};

