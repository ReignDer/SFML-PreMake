#include "AirplaneSupport.h"

#include "Scripts/Components/LionAnimation.h"
#include "Scripts/Components/SpriteChange.h"

AirplaneSupport::AirplaneSupport(std::string name) : Core::Entity(name), Core::CollisionListener()
{
}

void AirplaneSupport::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("CircusSheet"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);

	const rapidjson::Document& docs = TextureManager::getInstance()->getDoc();
	doc.CopyFrom(docs,doc.GetAllocator());

	if (doc.HasMember("frames") && doc["frames"].IsObject()) {
		const rapidjson::Value& frames = doc["frames"];

		for (rapidjson::Value::ConstMemberIterator it = frames.MemberBegin(); it != frames.MemberEnd(); it++)
		{
			std::string name = it->name.GetString();
			const rapidjson::Value& frameValue = it->value;

			//LOG(name);
			if (name == "sprite294" || name == "sprite295" || name == "sprite296" || name == "sprite297"){
				if (frameValue.HasMember("frame") && frameValue["frame"].IsObject()) {
					const rapidjson::Value& frame = frameValue["frame"];
					int x = frame["x"].GetInt();
					int y = frame["y"].GetInt();
					int w = frame["w"].GetInt();
					int h = frame["h"].GetInt();

					values.emplace_back(x,y,w,h);
					LOG(name);

				}
				if (frameValue.HasMember("spriteSourceSize") && frameValue["spriteSourceSize"].IsObject()) {
					const rapidjson::Value& spriteSourceSize = frameValue["spriteSourceSize"];

					int x = spriteSourceSize["x"].GetInt();
					int y = spriteSourceSize["y"].GetInt();
					int w = spriteSourceSize["w"].GetInt();
					int h = spriteSourceSize["h"].GetInt();


				}
				if (frameValue.HasMember("sourceSize") && frameValue["sourceSize"].IsObject()) {
					const rapidjson::Value& sourceSize = frameValue["spriteSourceSize"];

					int w = sourceSize["w"].GetInt();
					int h = sourceSize["h"].GetInt();
					m_Sprite->setOrigin(w / 2.f, h / 2.f);
				}
			}
		}
	}

	m_Sprite->setScale(2.3f,2.3f);
	m_Sprite->setTextureRect(values[2]);
	m_Border = m_Sprite->getGlobalBounds();
	m_Sprite->setPosition(250, 303);
	m_Sprite->setRotation(0.0f);

	auto renderer = new Core::RendererComponent("AirplaneSupportSprite");
	renderer->assignDrawable(m_Sprite);
	this->attachComponent(renderer);

	auto spriteAnimation = new SpriteChange("AirplaneSupportSprite");
	attachComponent(spriteAnimation);
	
}

void AirplaneSupport::perform()
{
}

void AirplaneSupport::OnCollisionEnter(Entity* entity)
{
	
}

void AirplaneSupport::OnCollisionExit(Entity* entity)
{
	
}

void AirplaneSupport::OnCollisionStay(Entity* entity)
{
	
}


