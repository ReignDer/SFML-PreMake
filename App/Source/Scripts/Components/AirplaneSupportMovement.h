#pragma once
#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Player.h"
#include "Scripts/Components/PlayerInputController.h"
class AirplaneSupportMovement : public Core::AbstractComponent
{
public:
	AirplaneSupportMovement(std::string name);
	virtual void perform() override;
private:
	const float SPEED = 300.f;
};

