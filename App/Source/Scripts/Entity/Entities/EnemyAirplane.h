#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Components/EnemyBehaviour.h"
#include "Scripts/Poolables/EntityPoolable.h"
class EnemyAirplane : public EntityPoolable, public Core::CollisionListener
{
public:
	EnemyAirplane(const std::string& name);
	virtual ~EnemyAirplane();
	virtual void initialize() override;

	virtual void OnRelease() override;
	virtual void OnActivate() override;

	virtual EntityPoolable* clone() override { return new EnemyAirplane(name); }

	virtual void OnCollisionEnter(Core::Entity* entity) override;
	virtual void OnCollisionExit(Core::Entity* entity) override;

private:

	int counter = 0;
	const int SPAWN_RANGE = 300;

	Core::ColliderComponent* m_Collider;

};

