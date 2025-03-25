#include "Corepch.h"
#include "Component.h"

namespace Core {
	AbstractComponent::AbstractComponent(const std::string& name, ComponentType type)
	{
		this->name = name;
		owner = nullptr;
		this->type = type;
	}

	AbstractComponent::~AbstractComponent()
	{
		owner = nullptr;
		type = NotSet;
	}

	void AbstractComponent::attachOwner(Entity* entity)
	{
		owner = entity;
		
	}

	void AbstractComponent::dettachOwner()
	{
		delete this;

	}


}
