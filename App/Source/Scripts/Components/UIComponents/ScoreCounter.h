#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"

class ScoreCounter : public Core::AbstractComponent
{
public:
	ScoreCounter(std::string name, UIText* text);
	virtual void perform() override;
	void increaseScore(int score);
	void reset();

private:
	UIText* text;
	int score = 0;
};

