#include "Corepch.h"
#include "WindowsInput.h"

namespace Core {
	//TODO: FINISH IMPLEMENTATION
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::KeyPressedImpl(sf::Keyboard::Key keyCode)
	{
		auto window = static_cast<sf::RenderWindow*>(Core::Get().GetWindow().GetNativeWindow()); 

		auto state = sf::Keyboard::isKeyPressed(keyCode);

		return state;
	}

	bool WindowsInput::MouseButtonPressedImpl(int button)
	{
		return false;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<sf::RenderWindow*>(Core::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		auto state = sf::Mouse::getPosition(*window);
		window->mapPixelToCoords(state);
		xpos = state.x;
		ypos = state.y;

		return { (float)xpos, (float)ypos };
	}

	float WindowsInput::GetMouseXImpl()
	{
		return 0.0f;
	}

	float WindowsInput::GetMouseYImpl()
	{
		return 0.0f;
	}
}