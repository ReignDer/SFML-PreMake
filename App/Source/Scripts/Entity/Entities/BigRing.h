#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
class BigRing : public Core::Entity, public Core::CollisionListener
{
public:
    BigRing(std::string name);
    virtual ~BigRing();
    void initialize() override;
    void OnCollisionEnter(Entity* entity) override;
    void OnCollisionExit(Entity* entity) override;
    void OnCollisionStay(Entity* entity) override;
    bool m_ColliderActive = false;
    std::vector<sf::IntRect> getValues() { return values; }

private:
    float m_RingSpeed = 300.f;
    Core::ColliderComponent* m_Collider = nullptr;
    rapidjson::Document doc;
    std::vector<sf::IntRect> values;
};