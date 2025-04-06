#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "Scripts/Managers/SFXManager.h"
#include "Scripts/Managers/GameManager.h"
#include "Scripts/Components/UIComponents/HighScoreCounter.h"
#include "UIButton.h"
#include "UIText.h"
class GameOverScreen : public Core::Entity, public IButtonListener
{
public:
	GameOverScreen(const std::string& name);
	virtual ~GameOverScreen();
	virtual void initialize() override;
	virtual void OnButtonClick(UIButton* button) override;
	virtual void OnButtonReleased(UIButton* button) override;

};

