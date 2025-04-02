#include "BGMovement.h"

BGMovement::BGMovement(std::string name) : AbstractComponent(name,Script)
{
}

void BGMovement::perform()
{
	BGObject* bgObject = (BGObject*)this->getOwner();
	sf::Transformable* bgTransformable = bgObject->getTransformable();

	if (bgTransformable == nullptr) {
		LOG("BGTransformable not found");
	}

	sf::Vector2f offset(0.0f, 0.0f);
	offset.x += SPEED_MULTIPLIER;
	bgTransformable->move(offset * timestep.asSeconds());
	sf::Vector2f localPos = bgTransformable->getPosition();

	if (localPos.x * timestep.asSeconds() > 6.0f)
		bgTransformable->setPosition(-300, 0);


}
