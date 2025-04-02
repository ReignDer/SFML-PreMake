#pragma once
#include "Builder.h"

class Floor : public Core::EmptyEntity, Core::CollisionListener
{
public:
    Floor(const std::string& name);
    virtual ~Floor();

    virtual void initialize() override;

    void OnCollisionEnter(Entity* entity) override;
    void OnCollisionExit(Entity* entity) override;

private:
    std::shared_ptr<sf::RectangleShape> rect;
    Core::ColliderComponent* m_Collider = nullptr;
};
