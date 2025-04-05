#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Poolables/EntityPoolable.h"

class FirePots : public EntityPoolable, public Core::CollisionListener
{
public:
    FirePots(std::string name);
    virtual ~FirePots();
    virtual void initialize() override;
    virtual void OnRelease() override;
    virtual void OnActivate() override;

    virtual EntityPoolable* clone() override { return new FirePots(name); }
    
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
