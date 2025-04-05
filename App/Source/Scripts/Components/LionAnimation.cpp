#include "LionAnimation.h"

#include "Scripts/Entity/Entities/AirplaneSupport.h"

LionAnimation::LionAnimation(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void LionAnimation::perform()
{
    auto atlas = static_cast<AirplaneSupport*>(getOwner());
    auto values = atlas->getValues();
    m_Ticks += timestep.asSeconds();

    if (Core::Input::IsKeyPressed(sf::Keyboard::A) && m_Ticks > 0.16f) {
        reset();
        currentIndex++;
        if (currentIndex > 2) {
            currentIndex = 0;
        }
        atlas->setSprite(values[currentIndex]);
    }

    if (Core::Input::IsKeyPressed(sf::Keyboard::D) && m_Ticks > 0.16f) {
        reset();
        currentIndex--;
        if (currentIndex < 3) {
            currentIndex = 5;
        }
        atlas->setSprite(values[currentIndex]);
    }
}

void LionAnimation::reset()
{
    m_Ticks = 0.0f;
}