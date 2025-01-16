#include "Corepch.h"
#include "WindowsWindow.h"

namespace Core {
	Window* Window::Create(const WindowProperties& properties) {
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Init(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Close();
	}

	void WindowsWindow::OnUpdate()
	{
		//sf::Event event;
		//while (m_Window->pollEvent(event)) {
		//	std::cout << "Event";
		//	if (event.type == sf::Event::Closed) {
		//		m_Window->close();
		//	}


		//}

		m_Window->display();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;
		m_Window = new sf::RenderWindow(sf::VideoMode(m_Data.Width, m_Data.Height),m_Data.Title);

		m_Window->setVerticalSyncEnabled(true);
		m_Window->setFramerateLimit(60.f);
	}

	void WindowsWindow::Close()
	{
		if (m_Window) {
			m_Window->close();
			delete m_Window;
			m_Window = nullptr;
		}
	}
}