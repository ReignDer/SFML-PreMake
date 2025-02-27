#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = nullptr;

TextureManager* TextureManager::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new TextureManager();
    }
    return sharedInstance;
}

void TextureManager::loadAll()
{
    loadTexture("desert_bg", "Media/Desert.png");
    loadTexture("eagle", "Media/Eagle.png");
    loadTexture("raptor", "Media/Raptor.png");
    loadTexture("avenger", "Media/Avenger.png");
    loadTexture("b_4", "Media/b_4.png");
    loadTexture("b_5", "Media/b_5.png");
    loadTexture("bar_1", "Media/bar_1.png");
    loadTexture("f", "Media/f.png");
    loadTexture("TitleScreen", "Media/TitleScreenBG.png");
  
}

void TextureManager::loadTitle()
{
    loadTexture("TitleScreen", "Media/TitleScreenBG.png");
    loadTexture("b_4", "Media/b_4.png");
    loadTexture("b_5", "Media/b_5.png");
}

void TextureManager::loadGame()
{
    loadTexture("desert_bg", "Media/Desert.png");
    loadTexture("eagle", "Media/Eagle.png");
    loadTexture("raptor", "Media/Raptor.png");
    loadTexture("avenger", "Media/Avenger.png");
    loadTexture("b_4", "Media/b_4.png");
    loadTexture("b_5", "Media/b_5.png");
    loadTexture("bar_1", "Media/bar_1.png");
    loadTexture("f", "Media/f.png");
}

void TextureManager::loadTexture(const std::string& key, const std::string& path)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(path);
    texture_map[key] = std::move(texture);
}

std::shared_ptr<sf::Texture> TextureManager::getTexture(const std::string& key)
{
    if (texture_map[key] != nullptr)
        return texture_map[key];
    else {
        std::cout << "Failed to load";
        return nullptr;
    }
}

void TextureManager::deleteResources()
{
    for (auto& map : texture_map) {
        map.second.reset();
    }
    texture_map.clear();
}


