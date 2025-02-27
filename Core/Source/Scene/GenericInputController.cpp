#include "Corepch.h"
#include "GenericInputController.h"


namespace Core {
	GenericInputController::GenericInputController(const std::string& name) : AbstractComponent(name, AbstractComponent::ComponentType::Input)
	{
		type = Input;
	}

	GenericInputController::~GenericInputController()
	{
		AbstractComponent::~AbstractComponent();
	}


	void GenericInputController::assignEvent(const sf::Event& event)
	{
		//LOG(event.type);
		m_Event = event;
		
	}
}
