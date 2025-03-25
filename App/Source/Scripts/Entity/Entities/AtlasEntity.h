#pragma once
#include "Builder.h"
#include "Scripts/Managers/TextureManager.h"
#include "rapidjson/document.h"
#include "Scripts/Components/SpriteChange.h"
class AtlasEntity : public Core::Entity
{
public:
	AtlasEntity(const std::string& name);

	virtual void initialize() override;

	std::vector<sf::IntRect> getValues() { return values; }

private:
	rapidjson::Document doc;
	std::vector<sf::IntRect> values;
};

