#include "Corepch.h"
#include "RendererComponent.h"

#include "SpriteRenderer.h"

namespace Core
{
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
        m_Drawable = std::move(drawable);
    }

    void RendererComponent::assignRenderState(const sf::RenderStates& renderState)
    {
        m_RenderStates = &renderState;
    }

    RendererComponent* RendererComponent::CreateSprite(const std::string& name, std::shared_ptr<sf::Texture> texture)
    {
        return new SpriteRenderer(name, texture);
    }
}
