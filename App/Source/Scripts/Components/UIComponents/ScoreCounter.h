#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"
#include "Scripts/Managers/GameManager.h"

class ScoreCounter : public Core::AbstractComponent
{
public:
	ScoreCounter(std::string name, UIText* text);
	virtual void perform() override;

private:
	UIText* text;
	int score = 0;
};

