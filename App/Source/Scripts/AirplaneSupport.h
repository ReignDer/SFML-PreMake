#pragma once
#include "Builder.h"
#include "Managers/TextureManager.h"
class AirplaneSupport : public Core::Entity
{
public:
	AirplaneSupport(std::string name);
	void initialize() override;
	virtual void update(sf::Time timestep) override;
private:
	const float SPEED_MULTIPLIER = 70.f;
	bool m_Reverse = false;
};

