#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{

}

void Entity::SetTexture(sf::Texture texture)
{
	m_Texture = texture;
	m_Sprite.setTexture(m_Texture);
}

sf::Sprite* Entity::GetSprite()
{
	return &m_Sprite;
}
