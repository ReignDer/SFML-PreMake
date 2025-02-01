#pragma once
#include "Corepch.h"
namespace Core {
	class Input
	{
	public:
		inline static bool IsKeyPressed(sf::Keyboard::Key pressed) { return s_Instance->KeyPressedImpl(pressed); }
		inline static bool IsMousePressed(sf::Mouse::Button pressed) { return s_Instance->MouseButtonPressedImpl(pressed); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool KeyPressedImpl(sf::Keyboard::Key keyCode) = 0;
		virtual bool MouseButtonPressedImpl(sf::Mouse::Button button) = 0;

		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_Instance;

	};
}