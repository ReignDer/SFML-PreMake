#include "JSONScene.h"

JSONScene::JSONScene::JSONScene() : Core::AbstractScene("JSONScene")
{
}

void JSONScene::JSONScene::OnLoadResources()
{
	TextureManager::getInstance()->parseJSON();
	TextureManager::getInstance()->loadAtlas();

}

void JSONScene::JSONScene::OnLoadObjects()
{
	auto spriteSheet = new AtlasEntity("Dota2Atlas");
	registerEntity(spriteSheet);

}

void JSONScene::JSONScene::OnUnloadResources()
{
	TextureManager::getInstance()->deleteResources();
}
