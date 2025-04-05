#include "LionAnimation.h"

#include "Scripts/Entity/Entities/AirplaneSupport.h"
#include "Scripts/Entity/Entities/Player.h"

LionAnimation::LionAnimation(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void LionAnimation::perform()
{
    auto atlas = static_cast<Player*>(getOwner());
    auto values = atlas->getValues();
    m_Ticks += timestep.asSeconds();
    
    if (Core::Input::IsKeyPressed(sf::Keyboard::A) && m_Ticks > 0.16f) {
        reset();
        if (!atlas->m_ColliderActive) return;
        currentIndex++;
        if (currentIndex > 3) {
            currentIndex = 1;
        }
        atlas->setSprite(values[currentIndex]);
    }

    if (Core::Input::IsKeyPressed(sf::Keyboard::D) && m_Ticks > 0.16f) {
        reset();
        if (!atlas->m_ColliderActive) return;
        currentIndex--;
        if (currentIndex < 4) {
            currentIndex = 6;
        }
        atlas->setSprite(values[currentIndex]);
    }

    if (Core::Input::IsKeyPressed(sf::Keyboard::Space) && m_Ticks > 0.16f)
    {
        reset();
        
        if (currentIndex >= 4)
        {
            currentIndex = 7;
        }
        else
            currentIndex = 0;
        
        atlas->setSprite(values[currentIndex]);
    }
}

void LionAnimation::reset()
{
    m_Ticks = 0.0f;
}