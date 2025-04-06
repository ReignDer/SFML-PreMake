#include "Corepch.h"
#include "Entity.h"

namespace Core {
	Entity::Entity(const std::string& name = "")
	{
		this->name = name;
		m_Parent = nullptr;
	}

	Entity::~Entity()
	{
		for (const auto& components : m_ComponentList) {
			delete components;
		}
		m_ComponentList.clear();
		for (const auto& child : m_EntityChildList) {
			delete child;
		}
		
		m_EntityChildList.clear();
	}



	void Entity::update(const sf::Time& timestep)
	{
		if (!isEnabled()) return;

		if (moveable)
		{
			UpdatePosition(timestep);
			UpdateVelocity(timestep);

			resetForce();
		}
		
		std::vector<AbstractComponent*> componentList = getComponentsByType(AbstractComponent::ComponentType::Script);
		
		for (const auto& components : componentList) {
			components->setDeltaTime(timestep);
			components->perform();

		}

		for (const auto& entity : m_EntityChildList) {
			entity->update(timestep);
		}
	}

	void Entity::processInput(const sf::Event& event)
	{
		if (!isEnabled()) return;

		const auto& componentList = getComponentsByType(AbstractComponent::ComponentType::Input);

		for (const auto& components : componentList) {
			((GenericInputController*)(components))->assignEvent(event);
			components->perform();

		}

		for (const auto& entity : m_EntityChildList) {
			entity->processInput(event);
		}
	}

	void Entity::draw(sf::RenderStates renderState)
	{
		if (!isEnabled()) return;

		renderState.transform = renderState.transform * m_Transformable.getTransform();
		
		//std::shared_ptr<sf::RenderStates> sharedRenderState = std::make_shared<sf::RenderStates>(renderState);

		const auto& componentList = getComponentsByType(AbstractComponent::ComponentType::Renderer);
		
		for (const auto& component : componentList) {
			RendererComponent* renderer = (RendererComponent*)component;
			renderer->assignRenderState(renderState);
			renderer->perform();
		}
		/*if (m_Enabled)
			Renderer::Enter(*m_Sprite, renderState);*/
		//LOG(m_EntityChildList.size());
		for (const auto& entityChild : m_EntityChildList) {
			entityChild->draw(renderState);
		}
	}

	sf::Transform Entity::getGlobalTransform()
	{
		Entity* parentObj = this;
		std::vector<Entity*> parentList;
		while (parentObj != nullptr) {
			parentList.emplace_back(parentObj);
			parentObj = parentObj->getParent();
		}

		sf::Transform transform = sf::Transform::Identity;
		const int index = static_cast<int>(parentList.size()) - 1;
		for (int i = index; i >= 0; i--) {
			transform = transform * parentList[i]->getTransformable()->getTransform();
		}

		return transform;
	}

	void Entity::attachChild(Entity* childEntity)
	{
		m_EntityChildList.emplace_back(childEntity);
		childEntity->setParent(this);
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

	void Entity::setSprite(const sf::IntRect& rect)
	{
		m_Sprite->setTextureRect(rect);
	}


	void Entity::attachComponent(AbstractComponent* component)
	{
		m_ComponentList.emplace_back(component);
		
		component->attachOwner(this);
		
	}

	void Entity::dettachComponent(AbstractComponent*  component)
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
		for (const auto& entity : m_ComponentList) {
			if (entity->getName() == name) {
				return entity;
			}
		}

		return nullptr;
	}

	AbstractComponent* Entity::findComponentOfType(AbstractComponent::ComponentType type, const std::string& name)
	{
		for (const auto& entity : m_ComponentList) {
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

	void Entity::addForce(sf::Vector2f vector2)
	{
		m_AccumulatedForce += vector2;
		LOG(m_AccumulatedForce.y);
	}

	void Entity::UpdatePosition(const sf::Time& timestep)
	{
		m_Position = (m_Velocity * timestep.asSeconds()) + ((m_Acceleration * timestep.asSeconds() * timestep.asSeconds()) * (1.f/2.f)) + m_Position;
		m_Transformable.move(m_Position);
	}

	void Entity::UpdateVelocity(const sf::Time& timestep)
	{
		m_Acceleration += m_AccumulatedForce * (1/m_Mass);
		m_Velocity = (m_Acceleration * timestep.asSeconds()) + m_Velocity;
		m_Velocity = m_Velocity * powf(damping, timestep.asSeconds());
		
	}

	void Entity::resetForce()
	{
		m_AccumulatedForce = sf::Vector2f(0,0);
		m_Acceleration = sf::Vector2f(0,0);
	}

	sf::Vector2f Entity::getPosition() {
		return this->m_Position;
	}
}
