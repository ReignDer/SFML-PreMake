#include "PlayerInputController.h"

PlayerInputController::PlayerInputController(const std::string& name) : GenericInputController(name)
{
}

PlayerInputController::~PlayerInputController()
{
	Core::GenericInputController::~GenericInputController();
}

void PlayerInputController::perform()
{
	
}

bool PlayerInputController::isUp()
{
	return Core::Input::IsKeyPressed(sf::Keyboard::W);
}

bool PlayerInputController::isDown()
{
	return Core::Input::IsKeyPressed(sf::Keyboard::S);
}

bool PlayerInputController::isLeft()
{
	return Core::Input::IsKeyPressed(sf::Keyboard::D);
}

bool PlayerInputController::isRight()
{
	return Core::Input::IsKeyPressed(sf::Keyboard::A);
}
