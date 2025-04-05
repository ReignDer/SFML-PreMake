#include "FirePots.h"

#include "Scripts/Components/FirePotAnimation.h"
#include "Scripts/Components/FirePotsMovement.h"

FirePots::FirePots(std::string name) : EntityPoolable(name), CollisionListener()
{
}

FirePots::~FirePots()
{
}

void FirePots::initialize()
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
			if (name == "sprite329" || name == "sprite330"){
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
	m_Sprite->setTextureRect(values[0]);
	m_Border = m_Sprite->getGlobalBounds();
	m_Sprite->setPosition(500, 200);
	m_Sprite->setRotation(0.0f);
	
	auto renderer = new Core::RendererComponent("FirePotsRenderer");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);
	
	m_Collider = new Core::ColliderComponent("Collider");
	m_Collider->setLocalBounds(m_Sprite->getGlobalBounds());
	m_Collider->setCollisionListener(this);
	attachComponent(m_Collider);

	auto firepotAnimation = new FirePotAnimation("FirePotAnimation");
	attachComponent(firepotAnimation);

	auto firePotsMovement = new FirePotsMovement("FirePotsMovement");
	attachComponent(firePotsMovement);
}

void FirePots::OnRelease()
{
	Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void FirePots::OnActivate()
{
	auto movement = (FirePotsMovement*)findComponentByName("FirePotsMovement");
	movement->configure(rand() % 50);
	Core::PhysicsManager::getInstance()->trackObject(m_Collider);
	setPosition(Core::Core::Get().GetWindow().GetWidth(), 210);
}

void FirePots::OnCollisionEnter(Entity* entity)
{
}

void FirePots::OnCollisionExit(Entity* entity)
{
}

void FirePots::OnCollisionStay(Entity* entity)
{
}
