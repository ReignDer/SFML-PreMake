#include "Corepch.h"
#include "Renderer.h"

namespace Core {



	void Renderer::StartScene()
	{
	}



	void Renderer::EndScene()
	{
	}

	void Renderer::Enter(const sf::Drawable& target)
	{
		RenderCommand::Draw(target);
	}

	void Renderer::Enter(const sf::Drawable& target, const sf::RenderStates& renderState)
	{
		RenderCommand::Draw(target, renderState);
		
	}

}
