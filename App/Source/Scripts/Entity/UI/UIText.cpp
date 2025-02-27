#include "UIText.h"

UIText::UIText(const std::string& name) : Core::Entity(name)
{
	m_Text = std::make_shared<sf::Text>();
}

void UIText::initialize()
{
	auto font = FontManager::getInstance()->getFont("default");
	m_Text->setFont(*font);
	m_Text->setFillColor(sf::Color::White);
	m_Text->setOutlineColor(sf::Color::Black);
	m_Text->setOutlineThickness(4.0f);

	setSize(40);
	setText("<Using placeholder!>");

	auto renderer = new Core::RendererComponent("Text");
	renderer->assignDrawable(m_Text);
	attachComponent(renderer);
}

void UIText::setText(const std::string& text)
{
	m_Text->setString(text);
	sf::FloatRect bounds = m_Text->getLocalBounds();

	m_Text->setOrigin(bounds.width / 2, bounds.height / 2);
}

const std::string& UIText::getText()
{
	return m_Text->getString();
}

void UIText::setSize(uint32_t size)
{
	m_Text->setCharacterSize(size);
}
