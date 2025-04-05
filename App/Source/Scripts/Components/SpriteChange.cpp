#include "SpriteChange.h"

#include "Scripts/Entity/Entities/Player.h"

SpriteChange::SpriteChange(const std::string& name) : Core::AbstractComponent(name, Script)
{
}

void SpriteChange::perform()
{
	auto atlas = static_cast<Player*>(getOwner());
	auto values = atlas->getValues();
	m_Ticks += timestep.asSeconds();

	if (Core::Input::IsKeyPressed(sf::Keyboard::A) && m_Ticks > 0.16f) {
		reset();
		currentIndex--;
		if (currentIndex < 0) {
			currentIndex = 1;
		}
		atlas->setSprite(values[currentIndex]);
	}

	if (Core::Input::IsKeyPressed(sf::Keyboard::D) && m_Ticks > 0.16f) {
		reset();
		currentIndex++;
		if (currentIndex > values.size() - 1) {
			currentIndex = 2;
		}
		atlas->setSprite(values[currentIndex]);
	}
}

void SpriteChange::reset()
{
	m_Ticks = 0.0f;
}
