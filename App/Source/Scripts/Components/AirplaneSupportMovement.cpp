#include "AirplaneSupportMovement.h"

AirplaneSupportMovement::AirplaneSupportMovement(std::string name) : AbstractComponent(name, Script)
{
}

void AirplaneSupportMovement::perform()
{
	Player* player = (Player*)this->getOwner();

	//LOG(player->getComponentListSize());
	auto input = (PlayerInputController*)player->getComponentsByType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = player->getTransformable();

	if (playerTransformable == nullptr || input == nullptr) {
		LOG("PlayerTransformable not found");
	}
	
	sf::Vector2f movement(0.f, 0.f);

	if (input->isUp()) {
		movement.y -= 1;
		

	}
	if (input->isDown()) {
		movement.y += 1;

	}
	m_Ticks += timestep.asSeconds();
	if (Core::Input::IsKeyPressed(sf::Keyboard::D) && player->m_ColliderActive) {
		movement.x += 1;

	}
	else if (Core::Input::IsKeyPressed(sf::Keyboard::A) && player->m_ColliderActive) {
		movement.x -= 1;
	}

	else if (Core::Input::IsKeyPressed(sf::Keyboard::Space) && player->m_ColliderActive && m_Ticks > BULLET_SPAWN_INTERVAL)
	{
		playerTransformable->move(0,-15.f);
		this->getOwner()->addForce({0,-9000.f});
		//this->getOwner()->resetForce();

		SFXManager::getInstance()->play("Jump");
	}

	if (input->hasFire() && m_Ticks > BULLET_SPAWN_INTERVAL) {
		auto m_ProjectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		m_Ticks = 0.0f;
		m_ProjectilePool->requestPoolable();
	}

	//if (Core::Input::IsMousePressed(sf::Mouse::Left)) {
	//	sf::Vector2f mousePos(Core::Input::GetMousePosition().first, Core::Input::GetMousePosition().second);

	//	movement = mousePos - m_Transformable.getPosition();


	//	movement = movement / std::sqrt(movement.x * movement.x + movement.y * movement.y);

	//}

	/*sf::Vector2f up = (sf::Vector2f)sf::Mouse::getPosition() -  m_Player.GetSprite()->getPosition();
	m_Player.GetSprite()->getTransform().transformPoint(up);*/
	//sf::Vector2f direction = movement;
	//double angle = std::atan2f(movement.x, -movement.y) * 180.0f / 3.14159f;
	////m_Sprite->move(movement * timestep.asSeconds() * m_PlayerSpeed);
	playerTransformable->move(movement * timestep.asSeconds() * SPEED);
	//LOG(playerTransformable->getPosition().y);

	//if (movement != sf::Vector2f(0.0f, 0.0f))
	//	playerTransformable->setRotation(angle);
}
