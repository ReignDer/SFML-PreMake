#include "BonusCounter.h"

BonusCounter::BonusCounter(std::string name, UIText* text) : AbstractComponent(name, Script)
{
	this->text = text;
}

void BonusCounter::perform()
{
	ticks += timestep.asSeconds();
	std::string string = "BONUS-";

	bonus = 5000 - int(ticks * 4) * 10;
	if (bonus <= 0) bonus = 0;

	string += std::to_string(bonus);

	this->text->setText(string);
}

void BonusCounter::reset() {
	this->ticks = 0;
}