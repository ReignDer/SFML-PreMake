#include "GameLayerScene.h"

#include "Scripts/Components/ObstacleHandler.h"
#include "Scripts/Entity/Entities/BigRing.h"
#include "Scripts/Entity/Entities/FirePots.h"
#include "Scripts/Entity/Entities/Floor.h"
#include "Scripts/Entity/Entities/SmallRing.h"

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
	floor->m_Mass = 1.f;
	registerEntity(floor);
	Core::PhysicsWorld::getInstance()->addEntity(floor);
	

	auto player = new Player("Player");
	player->m_Mass = 30.f;
	player->hasGravity = true;
	player->moveable = true;

	registerEntity(player);
	Core::PhysicsWorld::getInstance()->addEntity(player);

	
	auto support1 = new AirplaneSupport("support1");
	player->attachChild(support1);
	support1->setPosition(0, -100);
	

	auto enemiesManager = new Core::EmptyEntity("EnemiesManager");
	auto swarmHandler = new EnemySwarmHandler(3, "swarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	//registerEntity(enemiesManager);

	auto projectilePool = new EntityPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new ProjectileEntity("projectile"),10,nullptr);
	projectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);

	auto obstacleManager = new Core::EmptyEntity("ObstacleManager");
	auto obstacleHandler = new ObstacleHandler("ObstacleHander", 5, obstacleManager);
	obstacleManager->attachComponent(obstacleHandler);
	registerEntity(obstacleManager);
	
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
