#pragma once
#include "Builder.h"
#include <SFML/Graphics.hpp>
#include "Renderer/Renderer.h"
class EntityManager : private sf::NonCopyable
{
public:
	static EntityManager* getInstance();

	Core::Entity* findObjectByName(const std::string& name);
	std::vector<Core::Entity*> getAllEntities();
	int activeObjects();
	void update(sf::Time timestep);
	void render();

	void addEntity(Core::Entity* entity);

	void deleteObject(Core::Entity* entity);
	void deleteObjectByName(const std::string& name);
private:
	static EntityManager* sharedInstance;

	std::unordered_map<std::string, Core::Entity*> m_EntitiesMap;
	std::vector<Core::Entity*> m_EntitiesList;
};

