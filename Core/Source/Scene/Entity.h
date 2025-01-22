#pragma once
#include <SFML/Graphics.hpp>
namespace Core{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetTexture(const sf::Texture& texture);
		sf::Sprite* GetSprite();
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;
	};
}

