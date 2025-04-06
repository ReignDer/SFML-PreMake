#include "BGMHandler.h"

BGMHandler::BGMHandler(std::string name) : AbstractComponent(name, Script)
{
}

void BGMHandler::perform()
{
	if (!Core::SceneManager::getInstance()->isSceneLoaded(Core::SceneManager::GAME_SCENE_NAME))
		SFXManager::getInstance()->stop();
	else if (Core::EntityManager::getInstance()->findObjectByName("MainMenuScreen")->isEnabled())
		SFXManager::getInstance()->pause();
	else
		SFXManager::getInstance()->play();
}