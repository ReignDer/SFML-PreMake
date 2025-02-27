#include "EnemyAirplane.h"

EnemyAirplane::EnemyAirplane(const std::string& name) : EntityPoolable(name)
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
}

void EnemyAirplane::OnRelease()
{
	
}

void EnemyAirplane::OnActivate()
{
	auto behaviour = (EnemyBehaviour*)findComponentByName("AvengerBehaviour");
	behaviour->reset();

	setPosition(Core::Core::Get().GetWindow().GetWidth() / 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
}


