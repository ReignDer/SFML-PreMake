#include "GameManager.h"

void GameManager::increaseScore(int score) {
	this->score += score;
}

void GameManager::loseLife() {
	this->life--;
	if (life <= 0) this->loseGame();
}

int GameManager::getLife() {
	return this->life;
}

int GameManager::getScore() {
	return this->score;
}

void GameManager::loseGame() {
	this->score = 0;
	this->life = 3;

	Core::SceneManager::getInstance()->loadScene(Core::SceneManager::TITLE_SCENE_NAME);
}

GameManager* GameManager::sharedInstance = nullptr;

GameManager* GameManager::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new GameManager();
	}

	return sharedInstance;
};