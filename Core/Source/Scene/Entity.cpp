#include "Corepch.h"
#include "Entity.h"

namespace Core {
	Entity::Entity(const std::string& name = "")
	{
		this->name = name;
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


	void Entity::draw(sf::RenderStates renderState)
	{
		renderState.transform = renderState.transform * m_Transformable.getTransform();

		if(m_Enabled)
			Renderer::Enter(*m_Sprite, renderState);

		for (Entity* entityChild : m_EntityChildList) {
			entityChild->draw(renderState);
		}
	}

	void Entity::setEnabled(bool enabled)
	{
		m_Enabled = enabled;
	}
}
