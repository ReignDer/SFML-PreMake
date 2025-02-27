#pragma once
#include "Builder.h"
#include "Scripts/Entity/Interfaces/ButtonListener.h"
#include "Scripts/Entity/UI/UIButton.h"
class UIButtonInputController : public Core::GenericInputController
{
public:
	UIButtonInputController(const std::string& name, IButtonListener* buttonListener);
	virtual ~UIButtonInputController() = default;

	virtual void perform() override;

private:
	IButtonListener* m_ButtonListener;
	bool m_IsPressed = false;

};

