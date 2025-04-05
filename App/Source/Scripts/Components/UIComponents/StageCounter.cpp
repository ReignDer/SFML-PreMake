#include "StageCounter.h"

StageCounter::StageCounter(std::string name, UIText* text) : AbstractComponent(name, Script)
{
	this->text = text;
}

void StageCounter::perform()
{
	std::string string = "STAGE-";

	if (round < 10) string += std::to_string(0);
	string += std::to_string(round);

	this->text->setText(string);
}

void StageCounter::IncreaseRound() {
	this->round++;
}

void StageCounter::ResetRound() {
	this->round = 1;
}