#include "BGObject.h"

BGObject::BGObject(const std::string& name) : Core::Entity(name)
{
}

void BGObject::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("Circus_bg"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();

	m_Sprite->setScale(0.2,0.2);
	m_Sprite->setPosition(10, 0);
	m_Sprite->setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));

	auto bgMovement = new BGMovement("BGMovement");
	attachComponent(bgMovement);

	auto renderer = new Core::RendererComponent("BGObjectSprite");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);
}


