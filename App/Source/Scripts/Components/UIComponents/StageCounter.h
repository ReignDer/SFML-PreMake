#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include "Scripts/Entity/UI/UIText.h"

class StageCounter : public Core::AbstractComponent
{
public:
	StageCounter(std::string name, UIText* text);
	virtual void perform() override;
	void IncreaseRound();
	void ResetRound();

private:
	UIText* text;
	int round = 1;
};

