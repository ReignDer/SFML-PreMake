#include "Corepch.h"
#include "EntityManager.h"

#include "Physics/PhysicsWorld.h"

namespace Core {
	EntityManager* EntityManager::sharedInstance = nullptr;

	EntityManager* EntityManager::getInstance()
	{
		if (sharedInstance == nullptr) {
			sharedInstance = new EntityManager();
		}
		return sharedInstance;

	}

	Entity* EntityManager::findObjectByName(const std::string& name)
	{
		if (m_EntitiesMap[name] != nullptr) {
			return m_EntitiesMap[name];
		}
		else
			return nullptr;
	}

	std::vector<Entity*> EntityManager::getAllEntities()
	{
		return m_EntitiesList;
	}

	int EntityManager::activeObjects()
	{
		return static_cast<int>(m_EntitiesList.size());
	}

	void EntityManager::update(const sf::Time& timestep)
	{
		for (int i = 0; i < m_EntitiesList.size(); i++) {
			
			m_EntitiesList[i]->update(timestep);

		}
	}

	void EntityManager::processInput(const sf::Event& event)
	{

		for (int i = 0; i < m_EntitiesList.size(); i++) {

			m_EntitiesList[i]->processInput(event);
		}
	}

	void EntityManager::render()
	{
		for (int i = 0; i < m_EntitiesList.size(); i++) {
			m_EntitiesList[i]->draw(sf::RenderStates::Default);
		}
	}

	void EntityManager::addEntity(Entity* entity)
	{
		m_EntitiesMap[entity->getName()] = entity;
		m_EntitiesList.emplace_back(entity);
		entity->initialize();
	}

	void EntityManager::deleteObject(Entity* entity)
	{
		const std::string& key = entity->getName();
		//entity.reset();

		m_EntitiesMap.erase(key);

		m_EntitiesList.erase(std::remove(m_EntitiesList.begin(), m_EntitiesList.end(), entity));
		m_EntitiesList.shrink_to_fit();


	}

	void EntityManager::deleteObjectByName(const std::string& name)
	{
		Entity* entity = findObjectByName(name);

		if (entity != nullptr)
			deleteObject(entity);
	}
	void EntityManager::deleteAllObjectInScene()
	{
		for (auto& entity : m_EntitiesList) {
			LOG("DELETE ENTT");
			LOG(entity->getName());
			delete entity;
		}
		m_EntitiesList.clear();
		m_EntitiesList.shrink_to_fit();
		m_EntitiesMap.clear();
	}
}
