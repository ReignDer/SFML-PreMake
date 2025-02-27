#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Entity/Interfaces/ButtonListener.h"
#include "Scripts/Components/UIComponents/UIButtonInputController.h"
class UIButton : public Core::Entity
{
public:
	UIButton(const std::string& name, 
		std::shared_ptr<sf::Texture> normalTexutre,
		std::shared_ptr<sf::Texture> pressedTexutre);
	virtual void initialize() override;
	void changeButtonToNormal() { m_Sprite->setTexture(*m_NormalTexture); }
	void changeButtonToPressed() { m_Sprite->setTexture(*m_PressedTexture); };
	sf::FloatRect getLocalBounds() { return m_Sprite->getLocalBounds(); }
	sf::FloatRect getGlobalBounds();

	void setButtonListener(IButtonListener* button);

private:
	std::shared_ptr<sf::Texture> m_NormalTexture;
	std::shared_ptr<sf::Texture> m_PressedTexture;
	IButtonListener* m_ButtonListener;
};

