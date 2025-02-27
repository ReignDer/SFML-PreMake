#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Renderer/Renderer.h"

namespace Core {
	class EntityManager : private sf::NonCopyable
	{
	public:
		static EntityManager* getInstance();

		Entity* findObjectByName(const std::string& name);
		std::vector<Entity*> getAllEntities();
		int activeObjects();
		void update(const sf::Time& timestep);
		void processInput(const sf::Event& event);
		void render();

		void addEntity(Entity* entity);

		void deleteObject(Entity* entity);
		void deleteObjectByName(const std::string& name);
		void deleteAllObjectInScene();
	private:
		static EntityManager* sharedInstance;

		std::unordered_map<std::string, Entity*> m_EntitiesMap;
		std::vector<Entity*> m_EntitiesList;
	};
}

