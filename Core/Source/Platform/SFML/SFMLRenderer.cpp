#include "Corepch.h"
#include "SFMLRenderer.h"

namespace Core{
	void SFMLRenderer::Clear(sf::RenderWindow& window)
	{
		window.clear();

	}
	void SFMLRenderer::Draw(sf::RenderWindow& window,const sf::Drawable& render)
	{
		window.draw(render);
	}
	void SFMLRenderer::Draw(sf::RenderWindow& window, const sf::Drawable& render, const sf::RenderStates& renderState)
	{
		window.draw(render, renderState);

	}
}
