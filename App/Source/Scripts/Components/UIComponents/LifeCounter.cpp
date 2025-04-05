#include "LifeCounter.h"

LifeCounter::LifeCounter(std::string name, std::shared_ptr<sf::Texture> normalTexutre) : AbstractComponent(name, Script), Core::Entity(name)
{
	this->normalTexutre = normalTexutre;
}

void LifeCounter::initialize() {
	for (int i = 0; i < 3; i++) {
		m_Sprite = std::make_shared<sf::Sprite>();
		m_Sprite->setTexture(*normalTexutre);
		sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
		m_Sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
		m_Sprite->setScale(1, 1);

		auto renderer = new Core::RendererComponent("Button");
		renderer->assignDrawable(m_Sprite);
		attachComponent(renderer);

		lifeArray[0];
	}
}

void LifeCounter::perform()
{
	
}

void LifeCounter::reduceLife() {
	this->count--;
}

void LifeCounter::reset() {
	this->count = 3;
}