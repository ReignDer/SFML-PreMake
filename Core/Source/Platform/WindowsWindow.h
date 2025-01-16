#pragma once

#include <SFML/Graphics.hpp>
#include "Core/Window.h"
namespace Core {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();


		virtual void OnUpdate() override;

		inline virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }


		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline virtual sf::RenderWindow* GetNativeWindow() const { return m_Window; }


	private:
		virtual void Init(const WindowProperties& props);
		virtual void Close();

	private:
		sf::RenderWindow* m_Window;
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

