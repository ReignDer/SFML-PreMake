#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"
#include "Scripts/Entity/Entities.h"

class LifeCounter : public Core::AbstractComponent, Core::Entity
{
public:
	LifeCounter(std::string name, std::shared_ptr<sf::Texture> normalTexutre);
	virtual void initialize() override;
	virtual void perform() override;
	void reduceLife();
	void reset();

private:
	std::shared_ptr<sf::Texture> normalTexutre;
	std::shared_ptr<sf::Sprite> lifeArray[3];
	int count = 3;
};

