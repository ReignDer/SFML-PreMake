#include "Corepch.h"
#include "SpriteRenderer.h"

namespace Core {
	SpriteRenderer::SpriteRenderer(const std::string& name, std::shared_ptr<::sf::Texture> texture) :
		RendererComponent(name)
	{
		std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
		sprite->setTexture(*texture);
		sf::Vector2u textureSize = sprite->getTexture()->getSize();
		sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
		this->assignDrawable(sprite);
	}
}