#include "Player.h"


Player::Player(std::string name) : Core::Entity(name)
{
}

void Player::initialize()
{
	std::cout << name;
	m_Sprite = std::make_unique<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
	m_Sprite->setPosition(250, 250);
	m_Sprite->setRotation(0.0f);

	PlayerInputController* inputController = new PlayerInputController("PlayerInput");
	attachComponent(inputController);

	AirplaneSupportMovement* movement = new AirplaneSupportMovement("PlayerMovement");
	attachComponent(movement);

	Core::RendererComponent* renderer = new Core::RendererComponent("PlayerSprite");
	renderer->assignDrawable(*m_Sprite);
	attachComponent(renderer);
	
}



