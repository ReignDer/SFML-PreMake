#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Components/BGMovement.h"
class BGObject : public Core::Entity 
{
public:
	BGObject(const std::string& name);
	virtual void initialize() override;


private:
	const float SPEED_MULTIPLIER = 100.f;
};

