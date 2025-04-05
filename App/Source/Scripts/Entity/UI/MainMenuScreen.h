#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Managers/SFXManager.h"
#include "UIButton.h"
#include "UIText.h"
class MainMenuScreen : public Core::Entity, public IButtonListener
{
public:
	MainMenuScreen(const std::string& name);
	virtual ~MainMenuScreen();
	virtual void initialize() override;
	virtual void OnButtonClick(UIButton* button) override;
	virtual void OnButtonReleased(UIButton* button) override;

};

