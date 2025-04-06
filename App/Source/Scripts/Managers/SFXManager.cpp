#include "SFXManager.h"

SFXManager* SFXManager::sharedInstance = nullptr;

SFXManager* SFXManager::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new SFXManager();
    }
    return sharedInstance;
}
void SFXManager::deleteResources()
{
    for (auto itr = SFX_map.begin(); itr != SFX_map.end();) {
        auto buffer = itr->second->getBuffer();
        delete buffer;
        itr->second->resetBuffer();
        itr = SFX_map.erase(itr);

    }
}


void SFXManager::loadAll()
{
    loadSFX("Jump", "Media/SFX/Jump.wav");
    loadSFX("Applause", "Media/SFX/Applause.wav");
    loadSFX("Hit", "Media/SFX/Hit.wav");
    loadSFX("Click", "Media/SFX/Click.wav");
    loadSFX("BGM", "Media/SFX/BGM.wav");
}

void SFXManager::loadSFX(std::string key, std::string path)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(path);

    std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>();

    SFX_map[key] = std::move(sound);
    SFX_map[key]->setBuffer(*buffer);

    std::cout<<key<<std::endl;

}

void SFXManager::play(std::string key)
{
    if (SFX_map[key] == nullptr) return;

    //if(SFX_map[key]->getStatus() != sf::Sound::Playing)
        SFX_map[key]->play();

    /*
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
    */
}

void SFXManager::play()
{
    std::string key = "BGM";
    if (SFX_map[key] == nullptr) return;

    if(SFX_map[key]->getStatus() != sf::Sound::Playing)
        SFX_map[key]->play();
}

void SFXManager::pause()
{
    std::string key = "BGM";
    if (SFX_map[key] == nullptr) return;
    SFX_map[key]->pause();
}


void SFXManager::stop()
{
    std::string key = "BGM";
    if (SFX_map[key] == nullptr) return;
    SFX_map[key]->stop();
}




