#include "FontManager.h"

FontManager* FontManager::sharedInstance = nullptr;

FontManager* FontManager::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new FontManager();
    }
    return sharedInstance;
}

void FontManager::loadAll()
{
    loadFont("default", "Media/Pixeloid.ttf");
}

void FontManager::loadFont(const std::string& key, const std::string& path)
{
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    font->loadFromFile(path);
    m_FontMap[key] = std::move(font);
}

void FontManager::UnloadFont()
{
    for (auto& font : m_FontMap)
        font.second.reset();
    m_FontMap.clear();
}

std::shared_ptr<sf::Font> FontManager::getFont(const std::string& key)
{
    if (m_FontMap[key] != NULL) {
        return m_FontMap[key];
    }
    else
        return NULL;
} 
