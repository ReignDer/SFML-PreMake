#include "ScoreCounter.h"

ScoreCounter::ScoreCounter(std::string name, UIText* text) : AbstractComponent(name, Script)
{
	this->text = text;
}

void ScoreCounter::perform()
{
	std::string string = "SCORE-";
	this->score = GameManager::getInstance()->getScore();

	if (score < 10000) string += std::to_string(0);
	if (score < 1000) string += std::to_string(0);
	if (score < 100) string += std::to_string(0);
	if (score < 10) string += std::to_string(0);

	string += std::to_string(score);

	this->text->setText(string);
}