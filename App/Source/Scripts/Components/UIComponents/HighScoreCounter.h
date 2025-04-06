#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"
#include "Scripts/Managers/GameManager.h"

class HIghScoreCounter : public Core::AbstractComponent
{
public:
	HIghScoreCounter(std::string name, UIText* score, UIText* highscore);
	virtual void perform() override;

private:
	UIText* Score;
	UIText* Highscore;
	int score = 0;
	int highscore = 0;
};

