#pragma once
#include <SFML/Graphics.hpp>
#include "AbstractScene.h"



namespace Core {
	typedef std::unordered_map<std::string, AbstractScene*> SceneTable;
	typedef std::vector<std::string> SceneList;
	class SceneManager : private sf::NonCopyable
	{
	public:
		static std::string MAIN_MENU_SCENE_NAME;
		static std::string GAME_SCENE_NAME;
		static std::string TITLE_SCENE_NAME;

		static SceneManager* getInstance();
		void registerScene(AbstractScene* scene);
		void loadScene(const std::string& name);
		void unloadScene();
		bool isSceneLoaded(const std::string& name);
		void checkLoadScene();

	private:
		static SceneManager* sharedInstance;

		SceneTable m_StoredScenes;
		AbstractScene* m_ActiveScene;
		std::string m_ToLoadSceneName;
		bool m_IsLoading = false;
	};
}

