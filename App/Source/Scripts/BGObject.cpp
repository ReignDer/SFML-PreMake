#include "BGObject.h"

BGObject::BGObject(const std::string& name) : Core::Entity(name)
{
}

void BGObject::initialize()
{
	m_Sprite = std::make_unique<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("desert_bg"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();

	m_Sprite->setScale(2,2);
	m_Sprite->setPosition(0, -240);
}

void BGObject::update(sf::Time timestep)
{
	sf::Vector2f offset(0.0f, 0.0f);
	offset.y += SPEED_MULTIPLIER;
	m_Sprite->move(offset * timestep.asSeconds());
	sf::Vector2f localPos = m_Sprite->getPosition();

	if (localPos.y * timestep.asSeconds() > 0.f)
		m_Sprite->setPosition(0, -240);
}
