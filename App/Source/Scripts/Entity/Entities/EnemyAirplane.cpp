#include "EnemyAirplane.h"

EnemyAirplane::EnemyAirplane(const std::string& name) : EntityPoolable(name), CollisionListener()
{
}

EnemyAirplane::~EnemyAirplane()
{
}

void EnemyAirplane::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("avenger"));

	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x / 2, textureSize.y /2);

	this->setPosition(Core::Core::Get().GetWindow().GetWidth()/ 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand()%SPAWN_RANGE, 0);
	this->getTransformable()->setRotation(180);

	auto renderer = new Core::RendererComponent("EnemyAirplane");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

	auto behaviour = new EnemyBehaviour("AvengerBehaviour");
	attachComponent(behaviour);
	behaviour->configure(1.0f);

	m_Collider = new Core::ColliderComponent("EnemyCollider");
	m_Collider->setLocalBounds(m_Sprite->getGlobalBounds());
	m_Collider->setCollisionListener(this);
	attachComponent(m_Collider);
}

void EnemyAirplane::OnRelease()
{
	Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void EnemyAirplane::OnActivate()
{
	auto behaviour = (EnemyBehaviour*)findComponentByName("AvengerBehaviour");
	behaviour->reset();

	Core::PhysicsManager::getInstance()->trackObject(m_Collider);

	setPosition(Core::Core::Get().GetWindow().GetWidth() / 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 50);
}

void EnemyAirplane::OnCollisionEnter(Core::Entity* entity)
{
	if (entity->getName().find("projectile") != std::string::npos) {
		return;
		EntityPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
		enemyPool->releasePoolable((EntityPoolable*)this);
	}
}

void EnemyAirplane::OnCollisionExit(Core::Entity* entity)
{
}


