#pragma once

#include "RenderCommand.h"

namespace Core {
	class Renderer
	{
	public:
		static void StartScene();
		static void EndScene();
		static void Enter(const sf::Drawable& target);

	};
}

