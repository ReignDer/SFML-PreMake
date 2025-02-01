#pragma once
#include "Builder.h"
#include "Managers/TextureManager.h"
class BGObject : public Core::Entity 
{
public:
	BGObject(const std::string& name);
	virtual void initialize() override;
	virtual void update(sf::Time timestep) override;

private:
	const float SPEED_MULTIPLIER = 100.f;
};

