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
	Core::Core::Get().PauseApplication();
	
	if (Core::SceneManager::getInstance()->isSceneLoaded(Core::SceneManager::GAME_SCENE_NAME))
	Core::EntityManager::getInstance()->findObjectByName("GameOverScreen")->setEnabled(true);
}

void GameManager::resetStats() {
	int HighScore;
	std::string temp;
	this->prevScore = score;
	this->life = 3;

	std::fstream file("Source/Scripts/managers/HighScore.txt");

	if (!file.is_open()) {
		std::cout << "Error opening the file!";
		return;
	}

	std::getline(file, temp);
	HighScore = std::stoi(temp);

	if (this->score > HighScore)
		file << std::to_string(score);

	this->score = 0;
	file.close();
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
	std::string temp;

	std::ifstream file("Source/Scripts/managers/HighScore.txt");

	if (!file.is_open()) {
		std::cout << "Error opening the file!";
		return 0;
	}

	std::getline(file, temp);
	HighScore = std::stoi(temp);

	file.close();
	return HighScore;
}

GameManager* GameManager::sharedInstance = nullptr;

GameManager* GameManager::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new GameManager();
	}

	return sharedInstance;
};