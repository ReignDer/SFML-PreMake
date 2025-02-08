#include "Corepch.h"
#include "Entity.h"

namespace Core {
	Entity::Entity(const std::string& name = "")
	{
		this->name = name;
	}


	void Entity::update(sf::Time timestep)
	{
		if (!isEnabled()) return;

		std::vector<AbstractComponent*> componentList = getComponentsByType(AbstractComponent::ComponentType::Script);
		
		for (int i = 0; i < componentList.size(); i++) {
			componentList[i]->setDeltaTime(timestep);
			componentList[i]->perform();

		}

		for (int j = 0; j < m_EntityChildList.size(); j++) {
			m_EntityChildList[j]->update(timestep);
		}
	}

	void Entity::processInput(sf::Event& event)
	{
		if (!isEnabled()) return;

		const auto& componentList = getComponentsByType(AbstractComponent::ComponentType::Input);

		for (int i = 0; i < componentList.size(); i++) {
			((GenericInputController*)componentList[i])->assignEvent(event);
			componentList[i]->perform();

		}

		for (int j = 0; j < m_EntityChildList.size(); j++) {
			m_EntityChildList[j]->processInput(event);
		}
	}

	void Entity::draw(sf::RenderStates renderState)
	{
		if (!isEnabled()) return;

		renderState.transform = renderState.transform * m_Transformable.getTransform();

		const auto& componentList = getComponentsByType(AbstractComponent::ComponentType::Renderer);
		
		for (auto& component : m_ComponentList) {
			RendererComponent* renderer = (RendererComponent*)component;
			renderer->assignRenderState(renderState);
			renderer->perform();
		}
		/*if (m_Enabled)
			Renderer::Enter(*m_Sprite, renderState);*/
		//LOG(m_EntityChildList.size());
		for (auto& entityChild : m_EntityChildList) {
			entityChild->draw(renderState);
		}
	}

	void Entity::attachChild(Entity* childEntity)
	{
		m_EntityChildList.emplace_back(childEntity);
		childEntity->initialize();
	}

	void Entity::detachChild(Entity* childEntity)
	{
		int index = -1;
		for (int i = 0; i < m_EntityChildList.size(); i++) {
			if (m_EntityChildList[i] == childEntity) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			m_EntityChildList.erase(m_EntityChildList.begin() + index);
			m_EntityChildList.shrink_to_fit();
		}

	}

	void Entity::setPosition(float x, float y)
	{
		m_Transformable.setPosition(x, y);
	}




	void Entity::attachComponent(AbstractComponent* component)
	{
		m_ComponentList.emplace_back(component);
		component->attachOwner(this);
		
	}

	void Entity::dettachComponent(AbstractComponent* component)
	{
		int index = -1;

		for (int i = 0; i < m_ComponentList.size(); i++) {
			if (m_ComponentList[i] == component) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			m_ComponentList.erase(m_ComponentList.begin() + index);

		}
	}

	AbstractComponent* Entity::findComponentByName(const std::string& name)
	{
		for (auto& entity : m_ComponentList) {
			if (entity->getName() == name) {
				return entity;
			}
		}

		return nullptr;
	}

	AbstractComponent* Entity::findComponentOfType(AbstractComponent::ComponentType type, const std::string& name)
	{
		for (auto& entity : m_ComponentList) {
			if (entity->getName() == name && entity->getType() == type) {
				return entity;
			}
		}

		return nullptr;
	}

	std::vector<AbstractComponent*> Entity::getComponentsByType(AbstractComponent::ComponentType type)
	{	
		std::vector<AbstractComponent*> foundList;
		for (const auto& component : m_ComponentList) {

			if (component->getType() == type) {
				
				foundList.emplace_back(component);
			}
		}

		return foundList;
	}



	void Entity::setEnabled(bool enabled)
	{
		m_Enabled = enabled;
	}

}
