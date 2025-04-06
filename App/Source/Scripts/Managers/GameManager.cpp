#include "GameManager.h"
#include <iostream>
#include <fstream>

void GameManager::increaseScore(int score) {
	this->score += score;
}

void GameManager::loseLife() {
	SFXManager::getInstance()->play("Hit");
	this->life--;
	if (life <= 0) this->loseGame();
}

void GameManager::loseGame() {
	this->resetStats();

	SFXManager::getInstance()->stop();
	Core::EntityManager::getInstance()->findObjectByName("GameOverScreen")->setEnabled(true);
}

void GameManager::resetStats() {
	int HighScore;

	std::fstream file("HighScore.txt");
	file >> HighScore;

	if (this->score > HighScore)
		file << score;

	this->prevScore = score;
	this->score = 0;
	this->life = 3;
}

int GameManager::getLife() {
	return this->life;
}

int GameManager::getScore() {
	return this->score;
}

int GameManager::getPrevScore() {
	return this->prevScore;
}

int GameManager::getHighScore() {
	int HighScore;

	std::fstream file("HighScore.txt");
	file >> HighScore;

	return HighScore;
}

GameManager* GameManager::sharedInstance = nullptr;

GameManager* GameManager::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new GameManager();
	}

	return sharedInstance;
};