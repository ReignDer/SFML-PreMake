#include "Corepch.h"
#include "RenderCommand.h"

namespace Core {
	sf::RenderWindow* RenderCommand::m_Window = nullptr;
	SFMLRenderer* RenderCommand::s_SFMLRenderer = new SFMLRenderer;
}