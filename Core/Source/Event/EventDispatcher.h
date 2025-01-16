#pragma once

#include "Corepch.h"
#include <SFML/Window/Event.hpp>

namespace Core{
class EventDispatcher {
		using EventFn = std::function<bool(sf::Event&)>;
	public:
		EventDispatcher(sf::Event& event) : m_Event(event) {}
		template <sf::Event::EventType EventType>
		bool Dispatch(EventFn func) {
			if (m_Event.type == EventType) {
				return true;
			}

			return false;
		}

	private:
		sf::Event& m_Event;
	};
}