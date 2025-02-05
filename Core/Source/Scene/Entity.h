#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer/Renderer.h"
#include "Scene.h"
#include "Component.h"
#include "GenericInputController.h"
namespace Core{
	class Entity
	{
	public:
		Entity(const std::string& name);
		virtual ~Entity() = default;
		virtual void initialize() = 0;
		virtual void update(sf::Time timestep);
		virtual void processInput(sf::Event& event);
		virtual void draw(sf::RenderStates renderState);

		std::string getName() { return name; }
		std::string getName() const { return name; }

		sf::Transformable* getTransformable() { return &m_Transformable; }

		uint32_t getEntityID() { return m_EntityHandle; }
		uint32_t setEntityID(uint32_t entityHandle) { m_EntityHandle = entityHandle; }
		int getComponentListSize() { return m_ComponentList.size(); }

		void attachChild(Entity* childEntity);
		void detachChild(Entity* childEntity);
		void setPosition(float x, float y);

	public:
		////TODO: Call scene registry to check entity if it has the component
		//template<typename T>
		//bool HasComponent(){
		//	return;//
		//}
		//template<typename T>
		//bool GetComponent() {
		//	return;//
		//}

		//template<typename T>
		//bool AddComponent() {
		//	return;//
		//}

		void attachComponent(AbstractComponent* component);
		void dettachComponent(AbstractComponent* component);
		AbstractComponent* findComponentByName(const std::string& name);
		AbstractComponent* findComponentOfType(AbstractComponent::ComponentType type, const std::string& name);
		std::vector<AbstractComponent*> getComponentsByType(AbstractComponent::ComponentType type);
	
	public:
		void setEnabled(bool m_Enabled);
	protected:
		std::unique_ptr<sf::Texture> m_Texture;
		std::unique_ptr<sf::Sprite> m_Sprite;
		std::string name;
		bool m_Enabled = true;
		
		sf::Transformable m_Transformable;
		std::vector<Entity*> m_EntityChildList;
		std::vector<AbstractComponent*> m_ComponentList;
		
		uint32_t m_EntityHandle;
		//Scene* m_Scene;


	};
}

