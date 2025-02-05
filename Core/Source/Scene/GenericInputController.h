#pragma once
#include <SFML/Window/Event.hpp>
#include "Component.h"
namespace Core {
	class GenericInputController : public AbstractComponent {
	public:
		GenericInputController(const std::string& name);
		virtual ~GenericInputController();

		virtual void perform();
		void assignEvent(sf::Event event);
	protected:
		sf::Event event;
	};
}