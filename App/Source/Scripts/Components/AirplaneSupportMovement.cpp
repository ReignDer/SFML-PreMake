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
	
	m_Ticks += timestep.asSeconds();
	if (Core::Input::IsKeyPressed(sf::Keyboard::D) && player->m_ColliderActive) {
		movement.x += 1;
		
	}
	else if (Core::Input::IsKeyPressed(sf::Keyboard::A) && player->m_ColliderActive) {
		movement.x -= 1;
	}

	else if (Core::Input::IsKeyPressed(sf::Keyboard::Space) && player->m_ColliderActive && m_Ticks > 3.5f)
	{
		m_Ticks = 0.0f;
		playerTransformable->move(0,-15.f);
		this->getOwner()->addForce({0,-9000.f});
		//this->getOwner()->resetForce();

		SFXManager::getInstance()->play("Jump");
	}
	
	
	playerTransformable->move(movement * timestep.asSeconds() * SPEED);

}
