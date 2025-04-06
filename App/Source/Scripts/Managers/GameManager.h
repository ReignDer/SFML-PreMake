#pragma once

#include "Builder.h"
#include <SFML/Graphics.hpp>

class GameManager
{
public:
	void increaseScore(int score);
	void loseLife();
	void loseGame();

	int getLife();
	int getScore();

private:
	int life = 3;
	int score = 0;

public:
	static GameManager* getInstance();

private:
	GameManager() {};
	GameManager(GameManager const&) {};
	GameManager& operator=(GameManager const&) {};
	static GameManager* sharedInstance;
};

