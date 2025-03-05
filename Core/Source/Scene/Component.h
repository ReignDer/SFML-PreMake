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

	class RendererComponent : public AbstractComponent {
	public:
		RendererComponent(const std::string& name);
		virtual ~RendererComponent();
		virtual void perform();

		void assignDrawable(std::shared_ptr<sf::Drawable> drawable);
		void assignRenderState(const sf::RenderStates& renderState);

	private:
		std::shared_ptr<sf::Drawable> m_Drawable;
		const sf::RenderStates* m_RenderStates;
	};


}

