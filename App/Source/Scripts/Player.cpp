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
}

void Player::update(sf::Time timestep)
{
	handleMovement(timestep);
}

void Player::handleMovement(sf::Time timestep)
{
	for (int i = 0; i < m_EntityChildList.size(); i++) {
		m_EntityChildList[i]->update(timestep);
	}

	sf::Vector2f movement(0.f, 0.f);

	if (Core::Input::IsKeyPressed(sf::Keyboard::W)) {
		movement.y -= 1;
	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::S)) {
		movement.y += 1;

	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::D)) {
		movement.x += 1;

	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::A)) {
		movement.x -= 1;
	}

	//if (Core::Input::IsMousePressed(sf::Mouse::Left)) {
	//	sf::Vector2f mousePos(Core::Input::GetMousePosition().first, Core::Input::GetMousePosition().second);

	//	movement = mousePos - m_Transformable.getPosition();


	//	movement = movement / std::sqrt(movement.x * movement.x + movement.y * movement.y);

	//}

	/*sf::Vector2f up = (sf::Vector2f)sf::Mouse::getPosition() -  m_Player.GetSprite()->getPosition();
	m_Player.GetSprite()->getTransform().transformPoint(up);*/
	sf::Vector2f direction = movement;
	double angle = std::atan2f(movement.x, -movement.y) * 180.0f / 3.14159f;
	//m_Sprite->move(movement * timestep.asSeconds() * m_PlayerSpeed);
	m_Transformable.move(movement * timestep.asSeconds() * m_PlayerSpeed);


	if (movement != sf::Vector2f(0.0f, 0.0f))
		m_Sprite->setRotation(angle);
}
