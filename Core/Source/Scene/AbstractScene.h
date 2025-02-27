#pragma once
#include "Entity.h"
#include "EntityManager.h"

namespace Core {
	class AbstractScene
	{
	public:
		AbstractScene(const std::string& name);
		virtual void OnLoadResources() = 0;
		virtual void OnLoadObjects() = 0;

		virtual void OnUnloadResources() = 0;
		virtual void OnUnloadObjects();

		std::string getSceneName() { return name; }

	protected:
		void registerEntity(Entity* entity);
		std::string name;
	};
}

