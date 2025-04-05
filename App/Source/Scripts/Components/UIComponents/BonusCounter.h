#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"

class BonusCounter : public Core::AbstractComponent
{
public:
	BonusCounter(std::string name, UIText* text);
	virtual void perform() override;
	void reset();

private:
	UIText* text;
	int bonus = 5000;
	float ticks = 0;
};

