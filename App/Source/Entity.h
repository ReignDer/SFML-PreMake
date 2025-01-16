#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetTexture(sf::Texture texture);
	sf::Sprite* GetSprite();
private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};

