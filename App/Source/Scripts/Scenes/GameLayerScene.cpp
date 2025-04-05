#include "GameLayerScene.h"

#include "Scripts/Entity/Entities/Floor.h"

GameLayerScene::GameLayerScene() : AbstractScene("GameScene")
{
}

void GameLayerScene::OnLoadResources()
{
	TextureManager::getInstance()->loadGame();
	FontManager::getInstance()->loadAll();
}

void GameLayerScene::OnLoadObjects()
{
	auto physicsManager = new Core::EmptyEntity("Physics");
	Core::PhysicsManager::initialize("PhysicsManager", physicsManager);
	registerEntity(physicsManager);

	auto bgObject = new BGObject("BGObject");
	registerEntity(bgObject);

	auto floor = new Floor("Floor");
	registerEntity(floor);

	auto player = new Player("Player");
	player->m_Mass = 30.f;
	player->hasGravity = true;
	player->moveable = true;
	Core::PhysicsWorld::getInstance()->addEntity(player);
	registerEntity(player);

	

	auto support1 = new AirplaneSupport("support1");
	player->attachChild(support1);
	support1->setPosition(50, 100);

	auto support2 = new AirplaneSupport("support2");
	player->attachChild(support2);
	support2->setPosition(-50, 100);

	auto enemiesManager = new Core::EmptyEntity("EnemiesManager");
	auto swarmHandler = new EnemySwarmHandler(3, "swarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	registerEntity(enemiesManager);

	auto projectilePool = new EntityPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new ProjectileEntity("projectile"),10,nullptr);
	projectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);

	auto uiBar = new UIBar("Bar");
	registerEntity(uiBar);

	auto menu = new MainMenuScreen("MainMenuScreen");
	registerEntity(menu);

	
}

void GameLayerScene::OnUnloadResources()
{
	TextureManager::getInstance()->deleteResources();
	FontManager::getInstance()->UnloadFont();
}
