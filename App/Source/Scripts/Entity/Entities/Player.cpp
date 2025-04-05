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

	m_Border = m_Sprite->getGlobalBounds();

	m_Collider = new Core::ColliderComponent("Collider");
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
		m_ColliderActive = false;
		
	}
}

void Player::OnCollisionStay(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		m_ColliderActive = true;
		//m_Velocity.y = 0.0f;
		//m_Acceleration.y = 0.0f;
		//float overlap = this->m_Transformable.getPosition().y + this->m_Border.height - entity->m_Position.y;

		// Move the player up by the amount of overlap to ensure it's on top of the floor
		//if (overlap > 0)
		//{
		//	this->m_Transformable.move(0.0f, -overlap);
		//}
	}
}


