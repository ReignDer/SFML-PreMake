#pragma once

#include <SFML/Window/Event.hpp>
namespace Core {
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnRemove() {};
		virtual void OnUpdate(sf::Time timestep) {};

		virtual void OnEvent(sf::Event& event) {};

	protected:
		std::string m_DebugName;
	};
}


