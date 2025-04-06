#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Managers/GameManager.h"
#include "Scripts/Components/AirplaneSupportMovement.h"
#include "Scripts/Components/PlayerInputController.h"

class Player : public Core::Entity, public Core::CollisionListener
{
public:
	Player(std::string name);
	virtual ~Player();
	void initialize() override;
	void OnCollisionEnter(Entity* entity) override;
	void OnCollisionExit(Entity* entity) override;
	void OnCollisionStay(Entity* entity) override;
	bool m_ColliderActive = false;
	std::vector<sf::IntRect> getValues() { return values; }

private:
	float m_PlayerSpeed = 300.f;
	Core::ColliderComponent* m_Collider = nullptr;
	rapidjson::Document doc;
	std::vector<sf::IntRect> values;
	
};

