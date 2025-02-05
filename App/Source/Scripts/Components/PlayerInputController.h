#pragma once
#include "Builder.h"
#include "Scene/GenericInputController.h"
class PlayerInputController : public Core::GenericInputController
{
public:
	PlayerInputController(const std::string& name);
	virtual ~PlayerInputController();

	virtual void perform() override;
	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();

};

