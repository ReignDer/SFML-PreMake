#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
class AirplaneSupport : public Core::Entity, public Core::CollisionListener
{
public:
	AirplaneSupport(std::string name);
	void initialize() override;
	virtual void perform();
	void OnCollisionEnter(Entity* entity);
	void OnCollisionExit(Entity* entity);
	void OnCollisionStay(Entity* entity);
	
	std::vector<sf::IntRect> getValues() { return values; }
private:
	const float SPEED_MULTIPLIER = 70.f;
	bool m_Reverse = false;
	Core::ColliderComponent* m_Collider = nullptr;
	rapidjson::Document doc;
	std::vector<sf::IntRect> values;
};

