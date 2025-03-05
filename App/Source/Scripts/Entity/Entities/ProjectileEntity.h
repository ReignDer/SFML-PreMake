#pragma once
#include "Builder.h"
#include "Scripts/Poolables/EntityPoolable.h"
#include "Scripts/Components/ProjectileMovement.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Entity/Entities/Player.h"

class ProjectileEntity : public EntityPoolable , public Core::CollisionListener
{
public:
	ProjectileEntity(const std::string& name);
	virtual void initialize() override;
	virtual void OnRelease() override;
	virtual void OnActivate() override;

	virtual EntityPoolable* clone() override { return new ProjectileEntity(name); }

	virtual void OnCollisionEnter(Core::Entity* entity) override;
	virtual void OnCollisionExit(Core::Entity* entity) override;

private:
	ProjectileMovement* m_ProjectileMovement = nullptr;
	Core::ColliderComponent* m_Collider = nullptr;
	bool m_HasHit = false;
};

