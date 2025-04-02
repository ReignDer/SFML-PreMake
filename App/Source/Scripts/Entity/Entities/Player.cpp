#include "Player.h"

#include <algorithm>


Player::Player(std::string name) : Core::Entity(name), CollisionListener()
{
}

Player::~Player()
{
	//Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void Player::initialize()
{
	std::cout << name;
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
	m_Sprite->setPosition(250, 250);
	m_Sprite->setRotation(0.0f);

	m_Collider = new Core::ColliderComponent("PlayerCollider");
	m_Collider->setLocalBounds(m_Sprite->getGlobalBounds());
	m_Collider->setCollisionListener(this);
	attachComponent(m_Collider);

	auto inputController = new PlayerInputController("PlayerInput");
	attachComponent(inputController);

	auto movement = new AirplaneSupportMovement("PlayerMovement");
	attachComponent(movement);

	auto renderer = new Core::RendererComponent("PlayerSprite");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);
	Core::PhysicsManager::getInstance()->trackObject(m_Collider);
}

void Player::OnCollisionEnter(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		m_ColliderActive = true;
	}
}

void Player::OnCollisionExit(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		//m_ColliderActive = false;
	}
}




