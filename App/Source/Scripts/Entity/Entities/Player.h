#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Components/AirplaneSupportMovement.h"
#include "Scripts/Components/PlayerInputController.h"

class Player : public Core::Entity
{
public:
	Player(std::string name);
	void initialize() override;

	
private:
	float m_PlayerSpeed = 300.f;
};

