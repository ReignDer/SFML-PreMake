#include "Corepch.h"
#include "SceneManager.h"

namespace Core {
    std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
    std::string SceneManager::GAME_SCENE_NAME = "GameScene";
    std::string SceneManager::TITLE_SCENE_NAME = "TitleScene";
    std::string SceneManager::JSON_SCENE_NAME = "JSONScene";

    SceneManager* SceneManager::sharedInstance = nullptr;

    SceneManager* Core::SceneManager::getInstance()
    {
        if (sharedInstance == nullptr) {
            sharedInstance = new SceneManager();
        }
        else
            return sharedInstance;
    }

    void Core::SceneManager::registerScene(AbstractScene* scene)
    {
        m_StoredScenes[scene->getSceneName()] = scene;
    }

    void Core::SceneManager::loadScene(const std::string& name)
    {
        m_IsLoading = true;
        m_ToLoadSceneName = name;
    }

    void Core::SceneManager::unloadScene()
    {
        if (m_ActiveScene != nullptr) {
            m_ActiveScene->OnUnloadObjects();
            m_ActiveScene->OnUnloadResources();
        }
    }

    bool Core::SceneManager::isSceneLoaded(const std::string& name)
    {
        return m_ActiveScene->getSceneName() == name;
    }

    void Core::SceneManager::checkLoadScene()
    {
        if (m_IsLoading) {
            unloadScene();
            m_ActiveScene = m_StoredScenes[m_ToLoadSceneName];
            m_ActiveScene->OnLoadResources();
            m_ActiveScene->OnLoadObjects();
            m_IsLoading = false;
        }
    }
}
