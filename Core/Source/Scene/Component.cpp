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


	//Renderer Component
	RendererComponent::RendererComponent(const std::string& name) : 
		AbstractComponent(name, Renderer)
	{
		m_Drawable = nullptr;
		m_RenderStates = nullptr;
	
	}
	RendererComponent::~RendererComponent()
	{

		AbstractComponent::~AbstractComponent();
	}

	void RendererComponent::perform()
	{
		Renderer::Enter(*m_Drawable, *m_RenderStates);
	}

	void RendererComponent::assignDrawable(std::shared_ptr<sf::Drawable> drawable)
	{
		m_Drawable = drawable;
	}

	void RendererComponent::assignRenderState(const sf::RenderStates& renderState)
	{
		m_RenderStates = &renderState;
	}



}
