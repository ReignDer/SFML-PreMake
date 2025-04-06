#pragma once

#include "Builder.h"
#include <SFML/Graphics.hpp>
#include "Scripts/Managers/SFXManager.h"

class GameManager
{
public:
	void increaseScore(int score);
	void loseLife();
	void loseGame();
	void resetStats();

	int getLife();
	int getScore();
	int getPrevScore();
	int getHighScore();

private:
	int life = 3;
	int score = 0;
	int prevScore = 0;

public:
	static GameManager* getInstance();

private:
	GameManager() {};
	GameManager(GameManager const&) {};
	GameManager& operator=(GameManager const&) {};
	static GameManager* sharedInstance;
};

