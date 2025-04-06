#include "HIghScoreCounter.h"

HIghScoreCounter::HIghScoreCounter(std::string name, UIText* score, UIText* highscore) : AbstractComponent(name, Script)
{
	this->Score = score;
	this->Highscore = highscore;

}

void HIghScoreCounter::perform()
{
	std::string string = "HIGH SCORE:\n";
	this->highscore = GameManager::getInstance()->getHighScore();

	string += std::to_string(highscore);

	this->Highscore->setText(string);



	string = "SCORE:\n";
	this->score = GameManager::getInstance()->getPrevScore();

	string += std::to_string(score);

	this->Score->setText(string);	
}