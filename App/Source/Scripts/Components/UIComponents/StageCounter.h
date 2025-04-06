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
	float m_currentTicks = 0.0f;
	bool stage2 = false;
	bool stage3 = false;

private:
	UIText* text;
	int round = 1;
};

