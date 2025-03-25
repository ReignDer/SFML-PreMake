#pragma once
#include <SFML/Graphics.hpp>
#include "RendererComponent.h"
namespace Core {
	
	class SpriteRenderer
		: public RendererComponent
	{
	public:
		SpriteRenderer(const std::string& name, std::shared_ptr<::sf::Texture> texture);
		
	};
}

