#include "BonusCounter.h"

BonusCounter::BonusCounter(std::string name, UIText* text) : AbstractComponent(name, Script)
{
	this->text = text;
}

void BonusCounter::perform()
{
	ticks += timestep.asSeconds();
	std::string string = "TIME-";

	int temp;
	temp = int(ticks) / 60;
	ticks -= temp * 60;
	minutes += temp;

	if (minutes < 10) string += "0";
	string += std::to_string(minutes);
	string += ":";

	if (temp = ticks < 10) string += "0";
	string += std::to_string(int(ticks));

	this->text->setText(string);
}

void BonusCounter::reset() {
	this->ticks = 0;
}