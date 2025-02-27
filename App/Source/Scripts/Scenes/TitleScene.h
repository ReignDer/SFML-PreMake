#pragma once
#include "Builder.h"
#include  "Scripts/Managers/Managers.h"
#include  "Scripts/Entity/Entities.h"
#include  "Scripts/Components/AppComponent.h"
class TitleScene : public Core::AbstractScene
{
public:
	TitleScene();
	virtual void OnLoadResources() override;
	virtual void OnLoadObjects() override;

	virtual void OnUnloadResources() override;
};

