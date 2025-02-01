#pragma once
#include "Builder.h"
#include "Managers/TextureManager.h"
#include "Managers/EntityManager.h"

class Player : public Core::Entity
{
public:
	Player(std::string name);
	void initialize() override;
	virtual void update(sf::Time timestep) override;
	void handleMovement(sf::Time timestep);
private:
	float m_PlayerSpeed = 300.f;
};

