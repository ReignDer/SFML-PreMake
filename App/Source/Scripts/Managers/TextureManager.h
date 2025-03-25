#pragma once
#include "Builder.h"
#include <SFML/Graphics.hpp>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
class TextureManager : private sf::NonCopyable
{
public:
	static TextureManager* getInstance();
	void loadAll();
	void loadTitle();
	void loadGame();
	void parseJSON();
	void loadAtlas();
	rapidjson::Document& getDoc() { return m_Doc; }
    std::shared_ptr<sf::Texture> getTexture(const std::string& key);
	void deleteResources();


private:
	void loadTexture(const std::string& key, const std::string& path);

private:

	static TextureManager* sharedInstance;
	std::unordered_map <std::string, std::shared_ptr<sf::Texture>> texture_map;
	rapidjson::Document m_Doc;
};

