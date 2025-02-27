#include "GameLayerScene.h"

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

	auto bgObject = new BGObject("BGObject");
	registerEntity(bgObject);

	auto player = new Player("Player");
	registerEntity(player);

	auto support1 = new AirplaneSupport("support1");
	player->attachChild(support1);
	support1->setPosition(50, 100);

	auto support2 = new AirplaneSupport("support2");
	player->attachChild(support2);
	support2->setPosition(-50, 100);

	auto enemiesManager = new Core::EmptyEntity("EnemiesManager");
	auto swarmHandler = new EnemySwarmHandler(200, "swarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	registerEntity(enemiesManager);

	auto menu = new MainMenuScreen("MainMenuScreen");
	registerEntity(menu);

	auto uiBar = new UIBar("Bar");
	registerEntity(uiBar);

	
}

void GameLayerScene::OnUnloadResources()
{
	TextureManager::getInstance()->deleteResources();
	FontManager::getInstance()->UnloadFont();
}
