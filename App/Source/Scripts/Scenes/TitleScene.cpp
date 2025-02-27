#include "TitleScene.h"

TitleScene::TitleScene() : Core::AbstractScene("TitleScene")
{
}

void TitleScene::OnLoadResources()
{
	TextureManager::getInstance()->loadTitle();
	FontManager::getInstance()->loadAll();
}

void TitleScene::OnLoadObjects()
{
	auto titleScreen = new TitleScreen("TitleScreen");
	registerEntity(titleScreen);
}

void TitleScene::OnUnloadResources()
{
	TextureManager::getInstance()->deleteResources();
	FontManager::getInstance()->UnloadFont();
}
