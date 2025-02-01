#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer/Renderer.h"
namespace Core{
	class Entity
	{
	public:
		Entity(const std::string& name);
		virtual ~Entity() = default;
		virtual void initialize() = 0;
		virtual void update(sf::Time timestep) = 0;
		virtual void draw(sf::RenderStates renderState);

		std::string getName() { return name; }

		void attachChild(Entity* childEntity);
		void detachChild(Entity* childEntity);
		void setPosition(float x, float y);
	
	public:
		void setEnabled(bool m_Enabled);
	protected:
		std::unique_ptr<sf::Texture> m_Texture;
		std::unique_ptr<sf::Sprite> m_Sprite;
		std::string name;
		bool m_Enabled = true;
		
		sf::Transformable m_Transformable;
		std::vector<Entity*> m_EntityChildList;
	};
}

