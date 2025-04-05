#include "ScoreCounter.h"

ScoreCounter::ScoreCounter(std::string name, UIText* text) : AbstractComponent(name, Script)
{
	this->text = text;
}

void ScoreCounter::perform()
{
	std::string string = "1P-";

	if (score < 100000) string += std::to_string(0);
	if (score < 10000) string += std::to_string(0);
	if (score < 1000) string += std::to_string(0);
	if (score < 100) string += std::to_string(0);
	if (score < 10) string += std::to_string(0);

	string += std::to_string(score);

	this->text->setText(string);
}

void ScoreCounter::increaseScore(int score) {
	this->score += score;
}

void ScoreCounter::reset() {
	this->score = 0;
}