#pragma once
#include "Builder.h"
#include "Scripts/Managers/ObjectPoolHolder.h"
class EnemyBehaviour : public Core::AbstractComponent
{
public:
	enum EnemyMovementType { Delay = 0, Forward = 1, SlowForward = 2, Side = 3};
	EnemyBehaviour(const std::string& name);
	virtual ~EnemyBehaviour();
	virtual void perform() override;
	void configure(float delay);
	void reset();

private:
	const float SPEED = 300.f;
	EnemyBehaviour::EnemyMovementType m_MovementType = Forward;
	

	float duration = 0.0f;
	float m_Delay = 0.0f;
	float m_Ticks = 0.0f;



};

