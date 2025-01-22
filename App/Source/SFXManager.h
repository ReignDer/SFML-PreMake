#pragma once
#include "Builder.h"
#include <SFML/Audio.hpp>
class SFXManager
{
public:
	static SFXManager* getInstance();
	void loadAll();
	void play(std::string key);

private:
	void loadSFX(std::string key, std::string path);

private:
	SFXManager() {};
	SFXManager(SFXManager const&) {};
	SFXManager& operator= (SFXManager const&) {};
	static SFXManager* sharedInstance;
	std::unordered_map<std::string, sf::Sound*> SFX_map;
};

