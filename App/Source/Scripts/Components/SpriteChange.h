#pragma once
#include "Builder.h"
#include "Scripts/Entity/Entities/AtlasEntity.h"
#include "Scripts/Components/PlayerInputController.h"

class SpriteChange : public Core::AbstractComponent
{
public:
	SpriteChange(const std::string& name);
	virtual void perform() override;
	void reset();


private:
	int currentIndex = 0;
	float m_Ticks = 0.0f;

};

