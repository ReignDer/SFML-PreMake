#include "ProjectileEntity.h"

ProjectileEntity::ProjectileEntity(const std::string& name) : EntityPoolable(name), CollisionListener()
{
}

void ProjectileEntity::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("projectile"));

	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	auto renderer = new Core::RendererComponent("projectile");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

	m_ProjectileMovement = new ProjectileMovement("projectile_movement");
	attachComponent(m_ProjectileMovement);

	m_Collider = new Core::ColliderComponent("projectileCollider");

	m_Collider->setLocalBounds(m_Sprite->getGlobalBounds());
	m_Collider->setCollisionListener(this);

	attachComponent(m_Collider);
}

void ProjectileEntity::OnRelease()
{
	Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void ProjectileEntity::OnActivate()
{
	Player* player = (Player*)Core::EntityManager::getInstance()->findObjectByName("Player");
	sf::Vector2f position = player->getTransformable()->getPosition();
	setPosition(position.x, position.y);

	m_HasHit = false;

	Core::PhysicsManager::getInstance()->trackObject(m_Collider);
}

void ProjectileEntity::OnCollisionEnter(Core::Entity* entity)
{
	if (entity->getName().find("enemy") != std::string::npos && !m_HasHit) {
		m_HasHit = true;
		EntityPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		projectilePool->releasePoolable((EntityPoolable*)this);
		LOG("HIT");
	}
}

void ProjectileEntity::OnCollisionExit(Core::Entity* entity)
{
}

void ProjectileEntity::OnCollisionStay(Core::Entity* entity)
{
}
