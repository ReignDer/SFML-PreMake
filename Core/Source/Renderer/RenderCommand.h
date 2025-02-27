#pragma once
#include <SFML/Graphics.hpp>
#include "Platform/SFML/SFMLRenderer.h"

namespace Core {
	class RenderCommand
	{
	public:
		inline static void setWindow(sf::RenderWindow& window) {
			m_Window = &window;
		}
		inline static void Clear() {
			s_SFMLRenderer->Clear(*m_Window);
		}
		inline static void TransparentClear() {
			s_SFMLRenderer->TransparentClear(*m_Window);
		}
		inline static void Draw(const sf::Drawable& render) {
			s_SFMLRenderer->Draw(*m_Window,render);
		}
		inline static void Draw(const sf::Drawable& render, const sf::RenderStates& renderState) {
			s_SFMLRenderer->Draw(*m_Window, render, renderState);
		}
	private:
		static SFMLRenderer* s_SFMLRenderer;
		static sf::RenderWindow* m_Window;
	};
}

