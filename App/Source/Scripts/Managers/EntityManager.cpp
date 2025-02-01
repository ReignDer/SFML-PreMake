#include "EntityManager.h"


EntityManager* EntityManager::sharedInstance = nullptr;

EntityManager* EntityManager::getInstance()
{
	if (sharedInstance == nullptr) {
		sharedInstance = new EntityManager();
	}
	return sharedInstance;

}

Core::Entity* EntityManager::findObjectByName(const std::string& name)
{
	if (m_EntitiesMap[name] != nullptr) {
		return m_EntitiesMap[name];
	}
	else
		return nullptr;
}

std::vector<Core::Entity*> EntityManager::getAllEntities()
{
	return m_EntitiesList;
}

int EntityManager::activeObjects()
{
	return m_EntitiesList.size();
}

void EntityManager::update(sf::Time timestep)
{
	for (int i = 0; i < m_EntitiesList.size();i++) {
		m_EntitiesList[i]->update(timestep);
	}
}

void EntityManager::render()
{
	for (int i = 0; i < m_EntitiesList.size(); i++) {
		m_EntitiesList[i]->draw(sf::RenderStates::Default);
	}
}

void EntityManager::addEntity(Core::Entity* entity)
{
	m_EntitiesMap[entity->getName()] = entity;
	m_EntitiesList.emplace_back(entity);
	entity->initialize();
}

void EntityManager::deleteObject(Core::Entity* entity)
{
	const std::string& key = entity->getName();
	delete entity;

	m_EntitiesMap.erase(key);

	m_EntitiesList.erase(std::remove(m_EntitiesList.begin(),m_EntitiesList.end(),entity));
	m_EntitiesList.shrink_to_fit();


}

void EntityManager::deleteObjectByName(const std::string& name)
{
	Core::Entity* entity = findObjectByName(name);

	if(entity != nullptr)
		deleteObject(entity);
}
