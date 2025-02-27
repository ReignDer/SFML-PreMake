#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() : Core::AbstractScene("MainMenuScene")
{
}

void MainMenuScene::OnLoadResources()
{
	TextureManager::getInstance()->loadAll();
	FontManager::getInstance()->loadAll();

}

void MainMenuScene::OnLoadObjects()
{
	auto menuScreen = new MainMenuScreen("MainMenuScreen");
	registerEntity(menuScreen);
}

void MainMenuScene::OnUnloadResources()
{
	TextureManager::getInstance()->deleteResources();
	FontManager::getInstance()->UnloadFont();
}
