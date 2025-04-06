#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer/Renderer.h"
#include "Scene.h"
#include "RendererComponent.h"
#include "GenericInputController.h"
namespace Core{
	class Entity
	{
	public:
		Entity(const std::string& name);
		virtual ~Entity();
		virtual void initialize() = 0;
		virtual void update(const sf::Time& timestep);
		virtual void processInput(const sf::Event& event);
		virtual void draw(sf::RenderStates renderState);

		std::string getName() { return name; }
		std::string getName() const { return name; }

		sf::Transformable* getTransformable() { return &m_Transformable; }
		sf::Transform getGlobalTransform();
		std::shared_ptr<sf::Sprite> getSprite() { return m_Sprite; }

		uint32_t getEntityID() { return m_EntityHandle; }
		uint32_t setEntityID(uint32_t entityHandle) { m_EntityHandle = entityHandle; }
		int getComponentListSize() { return static_cast<int>(m_ComponentList.size()); }

		void attachChild(Entity* childEntity);
		void detachChild(Entity* childEntity);
		void setPosition(float x, float y);
		void setSprite(const sf::IntRect& rect);

		sf::Vector2f getPosition();

	public:

		void attachComponent(AbstractComponent*  component);
		void dettachComponent(AbstractComponent*  component);
		AbstractComponent*  findComponentByName(const std::string& name);
		AbstractComponent*  findComponentOfType(AbstractComponent::ComponentType type, const std::string& name);
		std::vector<AbstractComponent*> getComponentsByType(AbstractComponent::ComponentType type);
	
	public:
		Entity* getParent() { return m_Parent; }

		void setEnabled(bool m_Enabled);
		bool isEnabled() { return m_Enabled; }
	public:
		void addForce(sf::Vector2f vector2);
		float m_Mass = 1.0f;
		sf::Vector2f m_Velocity;
		sf::Vector2f m_Acceleration;
		sf::Vector2f m_Position;
		float m_Restitution = 0.f;
		bool moveable = false;
		float damping = 0.9f;
		bool hasGravity = false;
		std::shared_ptr<sf::Sprite> m_Sprite;
		sf::FloatRect m_Border;
		sf::Vector2f m_AccumulatedForce;
		void resetForce();
	
	protected:
		
		void UpdatePosition(const sf::Time& timestep);
		void UpdateVelocity(const sf::Time& timestep);
		


		

	protected:
		void setParent(Entity* entity) { m_Parent = entity; }

	protected:
		std::unique_ptr<sf::Texture> m_Texture;
		
		std::string name;
		Entity* m_Parent;
		bool m_Enabled = true;
		
		sf::Transformable m_Transformable;
		std::vector<Entity*> m_EntityChildList;
		std::vector<AbstractComponent*> m_ComponentList;
		
		uint32_t m_EntityHandle;

		//Scene* m_Scene;


	};
}

