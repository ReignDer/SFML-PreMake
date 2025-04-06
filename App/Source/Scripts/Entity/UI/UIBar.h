#pragma once
#include "Builder.h"
#include "Scripts/Entity/Interfaces/ButtonListener.h"
#include "Scripts/Managers/Managers.h"
#include "Scripts/Entity/Entities.h"
#include "Scripts/Components/UIComponents/ScoreCounter.h"
#include "Scripts/Components/UIComponents/BonusCounter.h"
#include "Scripts/Components/UIComponents/StageCounter.h"
#include "Scripts/Managers/SFXManager.h"

class UIBar : public Core::Entity, public IButtonListener
{
public:
	UIBar(const std::string& name);
	virtual void initialize() override;

	virtual void OnButtonClick(UIButton* button) override;
	virtual void OnButtonReleased(UIButton* button) override;
};

