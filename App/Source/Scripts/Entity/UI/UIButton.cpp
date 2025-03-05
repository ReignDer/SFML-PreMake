#include "UIButton.h"


UIButton::UIButton(const std::string& name, 
	std::shared_ptr<sf::Texture> normalTexutre, 
	std::shared_ptr<sf::Texture> pressedTexutre)
	: Core::Entity(name)
{
	m_NormalTexture = std::move(normalTexutre);
	m_PressedTexture = std::move(pressedTexutre);
}

void UIButton::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*m_NormalTexture);
	sf::Vector2u textureSize= m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	auto renderer = new Core::RendererComponent("Button");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

}

sf::FloatRect UIButton::getGlobalBounds()
{
	sf::FloatRect bounds = m_Sprite->getGlobalBounds();

	bounds = this->getGlobalTransform().transformRect(bounds);
	return bounds;
}

void UIButton::setButtonListener(IButtonListener* button)
{
	m_ButtonListener = button;
	auto input = new UIButtonInputController("UIButtonInput", m_ButtonListener);
	attachComponent(input);
}
