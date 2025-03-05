#include "AirplaneSupport.h"

AirplaneSupport::AirplaneSupport(std::string name) : Core::Entity(name)
{
}

void AirplaneSupport::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("raptor"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
	m_Sprite->setPosition(250, 250);
	m_Sprite->setRotation(0.0f);

	auto renderer = new Core::RendererComponent("AirplaneSupportSprite");
	renderer->assignDrawable(m_Sprite);
	this->attachComponent(renderer);
}

void AirplaneSupport::perform()
{
}


