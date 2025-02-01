#pragma once
#include <SFML/Graphics.hpp>
#include "Scene/Entity.h"

namespace Core {
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		//Entity CreateEntity();

		void OnUpdate(sf::Time timestep);
	private:


	};
}

