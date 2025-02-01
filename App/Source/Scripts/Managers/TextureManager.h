#pragma once
#include "Builder.h"
#include <SFML/Graphics.hpp>
class TextureManager : private sf::NonCopyable
{
public:
	static TextureManager* getInstance();
	void loadAll();
    std::shared_ptr<sf::Texture> getTexture(const std::string& key);
	void deleteResources();


private:
	void loadTexture(const std::string& key, const std::string& path);

private:

	static TextureManager* sharedInstance;
	std::unordered_map <std::string, std::shared_ptr<sf::Texture>> texture_map;
};

