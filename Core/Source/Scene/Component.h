#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer/Renderer.h"
namespace Core {
	class Entity;

	class AbstractComponent
	{
	public:
		enum ComponentType {NotSet = -1, Script = 0, Renderer = 1, Input = 2, Physics = 3};
		AbstractComponent(const std::string& name, ComponentType type);
		virtual ~AbstractComponent();

		void attachOwner(Entity* entity);
		void dettachOwner();
		Entity* getOwner() { return owner; }
		ComponentType getType() { return type;}
		std::string getName() { return name; }

		void setDeltaTime(const sf::Time& timestep) { this->timestep = timestep; }
		virtual void perform() = 0;

	protected:
		Entity* owner;
		ComponentType type;
		std::string name;
		sf::Time timestep;
	};


}

