#pragma once
#include "Builder.h"
#include  "Scripts/Managers/Managers.h"
#include  "Scripts/Entity/Entities.h"
#include  "Scripts/Components/AppComponent.h"
class JSONScene : public Core::AbstractScene
{
public:
	JSONScene();
	virtual void OnLoadResources() override;
	virtual void OnLoadObjects() override;

	virtual void OnUnloadResources() override;


};

