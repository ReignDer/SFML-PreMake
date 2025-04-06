#pragma once

#include "Builder.h"
#include <Scene/Component.h>
#include <Scripts/Managers/SFXManager.h>

class BGMHandler : public Core::AbstractComponent
{
public:
	BGMHandler(std::string name);
	virtual void perform() override;
};

