#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"

class FirePots : public Core::Entity, public Core::CollisionListener
{
public:
    FirePots(std::string name);
    virtual ~FirePots();
    void initialize() override;
    void OnCollisionEnter(Entity* entity) override;
    void OnCollisionExit(Entity* entity) override;
    void OnCollisionStay(Entity* entity) override;
    bool m_ColliderActive = false;
    std::vector<sf::IntRect> getValues() { return values; }

private:
    Core::ColliderComponent* m_Collider = nullptr;
    rapidjson::Document doc;
    std::vector<sf::IntRect> values;
};
