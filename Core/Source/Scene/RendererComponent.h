#pragma once
#include "Component.h"
namespace Core
{
    class RendererComponent : public AbstractComponent {
    public:
        RendererComponent(const std::string& name);
        virtual ~RendererComponent();
        virtual void perform();

        void assignDrawable(std::shared_ptr<sf::Drawable> drawable);
        void assignRenderState(const sf::RenderStates& renderState);

        static RendererComponent* CreateSprite(const std::string& name, std::shared_ptr<sf::Texture> texture);

    private:
        std::shared_ptr<sf::Drawable> m_Drawable;
        const sf::RenderStates* m_RenderStates;
    };
}
