#include "Corepch.h"
#include "Entity.h"

namespace Core {
	Entity::Entity()
	{
	}
	Entity::~Entity()
	{

	}

	void Entity::SetTexture(const sf::Texture& texture)
	{
		m_Texture = texture;
		m_Sprite.setTexture(m_Texture);
	}

	sf::Sprite* Entity::GetSprite()
	{
		return &m_Sprite;
	}
}
