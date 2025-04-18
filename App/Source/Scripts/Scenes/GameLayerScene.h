#pragma once
#include "Builder.h"
#include  "Scripts/Managers/Managers.h"
#include  "Scripts/Entity/Entities.h"
#include  "Scripts/Components/AppComponent.h"
#include  "Scripts/Components/BGMHandler.h"
#include  "Scripts/Entity/UI/GameOverScreen.h"

class GameLayerScene : public Core::AbstractScene
{
public:
	GameLayerScene();
	virtual void OnLoadResources() override;
	virtual void OnLoadObjects() override;

	virtual void OnUnloadResources() override;
};

