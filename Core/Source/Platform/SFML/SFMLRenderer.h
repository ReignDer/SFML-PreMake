#pragma once
#include <SFML/Graphics.hpp>

namespace Core {
	class SFMLRenderer
	{
	public:
		void Clear(sf::RenderWindow& window);

		void Draw(sf::RenderWindow& window, const sf::Drawable& render);
		void Draw(sf::RenderWindow& window, const sf::Drawable& render, const sf::RenderStates& renderState);

	};
}

