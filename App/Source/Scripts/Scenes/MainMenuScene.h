#pragma once
#include "Builder.h"
#include "Scripts/Entity/UI/MainMenuScreen.h"
class MainMenuScene : public Core::AbstractScene
{
public:
	MainMenuScene();
	virtual void OnLoadResources() override;
	virtual void OnLoadObjects() override;

	virtual void OnUnloadResources() override;
};

