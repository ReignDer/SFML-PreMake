#pragma once
#include "Corepch.h"
#include <SFML/Graphics.hpp>
namespace Core {

	struct WindowProperties {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Mathieu Marc I. Pobre",
			unsigned int width = 640,
			unsigned int height = 480) : Title(title), Width(width), Height(height) {}
	};
	class Window {
	public:
		using EventCallbackFn = std::function<void(sf::Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual sf::RenderWindow* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
