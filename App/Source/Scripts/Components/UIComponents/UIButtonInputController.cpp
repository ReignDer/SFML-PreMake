#include "UIButtonInputController.h"


UIButtonInputController::UIButtonInputController(const std::string& name, IButtonListener* buttonListener)
	: Core::GenericInputController(name)
{
	m_ButtonListener = buttonListener;
}



void UIButtonInputController::perform()
{
	UIButton* button = (UIButton*)getOwner();
	if (m_Event.type == sf::Event::MouseButtonReleased && m_Event.mouseButton.button == sf::Mouse::Left && m_IsPressed) {
		m_IsPressed = false;
		button->changeButtonToNormal();
		m_ButtonListener->OnButtonReleased(button);


	}

	if (m_Event.type == sf::Event::MouseButtonPressed && Core::Input::IsMousePressed(sf::Mouse::Left)) {
		sf::Vector2f mousePos(Core::Input::GetMousePosition().first, Core::Input::GetMousePosition().second);
		sf::FloatRect bounds = button->getGlobalBounds();

		if (bounds.contains(mousePos)) {
			m_IsPressed = true;
			button->changeButtonToPressed();
			m_ButtonListener->OnButtonClick(button);


		}
	}

}
