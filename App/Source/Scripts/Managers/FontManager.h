#pragma once
#include "Builder.h"
#include <SFML/Graphics.hpp>
class FontManager : private sf::NonCopyable
{
public:
	static FontManager* getInstance();
	void loadAll();
	void UnloadFont();
	std::shared_ptr<sf::Font> getFont(const std::string& key);
private:
	void loadFont(const std::string& key, const std::string& path);
	
	std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_FontMap;

	static FontManager* sharedInstance;
};

