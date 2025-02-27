#pragma once
#include "Builder.h"
#include "Scripts/Managers/FontManager.h"
class UIText : public Core::Entity
{
public:
	UIText(const std::string& name);
	virtual void initialize() override;
	void setText(const std::string& text);
	const std::string& getText();
	void setSize(uint32_t size);

private:
	std::shared_ptr<sf::Text> m_Text;
};

