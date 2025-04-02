#pragma once
#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/Entities/BGObject.h"

class BGMovement : public Core::AbstractComponent
{
public:
	BGMovement(std::string name);
	virtual void perform() override;
private:
	const float SPEED_MULTIPLIER = 100.f;

};

