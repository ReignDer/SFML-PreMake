#include "AirplaneSupport.h"

AirplaneSupport::AirplaneSupport(std::string name) : Core::Entity(name)
{
}

void AirplaneSupport::initialize()
{
	m_Sprite = std::make_unique<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("raptor"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
	m_Sprite->setPosition(250, 250);
	m_Sprite->setRotation(0.0f);
}


void AirplaneSupport::update(sf::Time timestep)
{
	sf::Vector2f offset(0,0);
	sf::Vector2f localPos = m_Transformable.getPosition();


	if (name == "support1") {
		if (localPos.x > -50 && !m_Reverse) {
			offset.x -= SPEED_MULTIPLIER;

		}

		if (localPos.x < 50 && m_Reverse) {
			offset.x += SPEED_MULTIPLIER;

		}

		if (localPos.x < -50 && !m_Reverse) {
			m_Reverse = true;
		}

		if (localPos.x > 50 && m_Reverse)
			m_Reverse = false;
	}
	else {



		if (localPos.x < 50 && !m_Reverse) {
			offset.x += SPEED_MULTIPLIER;

		}

		if (localPos.x > -50 && m_Reverse)
		{
			offset.x -= SPEED_MULTIPLIER;
		}

		if (localPos.x > 50 && !m_Reverse) {
			m_Reverse = true;
		}

		if (localPos.x < -50 && m_Reverse)
			m_Reverse = false;
	}


	m_Transformable.move(offset * timestep.asSeconds());
	
}
