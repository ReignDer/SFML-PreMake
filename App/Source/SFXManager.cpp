#include "SFXManager.h"

SFXManager* SFXManager::sharedInstance = NULL;

SFXManager* SFXManager::getInstance()
{
    if (sharedInstance == NULL) {
        sharedInstance = new SFXManager();
    }
    return sharedInstance;
}

void SFXManager::loadAll()
{

    loadSFX("SFX_1", "Media/SFX/EnemyGunFire.wav");
    loadSFX("SFX_2", "Media/SFX/Explosion1.wav");
    loadSFX("SFX_3", "Media/SFX/Explosion2.wav");
    loadSFX("SFX_4", "Media/SFX/LaunchMissile.wav");

}

void SFXManager::loadSFX(std::string key, std::string path)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(path);

    sf::Sound* sound = new sf::Sound();
    

    SFX_map[key] = sound;
    SFX_map[key]->setBuffer(*buffer);

    std::cout<<key<<std::endl;
}

void SFXManager::play(std::string key)
{
    if (SFX_map[key] == nullptr) return;

    if(SFX_map[key]->getStatus() != sf::Sound::Playing)
        SFX_map[key]->play();

    switch (SFX_map[key]->getStatus()) {
    case sf::Sound::Playing:
        std::cout << "Playing" << std::endl;
        break;
    case sf::Sound::Paused:
        std::cout << "Paused" << std::endl;
        break;
    case sf::Sound::Stopped:
        std::cout << "Stopped" << std::endl;
        break;
    }

    
}
