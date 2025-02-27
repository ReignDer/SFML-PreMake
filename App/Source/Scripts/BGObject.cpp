#include "BGObject.h"

BGObject::BGObject(const std::string& name) : Core::Entity(name)
{
}

void BGObject::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("desert_bg"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();

	m_Sprite->setScale(2,2);
	m_Sprite->setPosition(0, -100);

	auto bgMovement = new BGMovement("BGMovement");
	attachComponent(bgMovement);

	auto renderer = new Core::RendererComponent("BGObjectSprite");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);
}


