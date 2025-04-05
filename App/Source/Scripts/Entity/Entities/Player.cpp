#include "Player.h"

#include <algorithm>

#include "Scripts/Components/LionAnimation.h"
#include "Scripts/Components/SpriteChange.h"


Player::Player(std::string name) : Core::Entity(name), CollisionListener()
{
}

Player::~Player()
{
	//Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void Player::initialize()
{
	std::cout << name;
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
			if (name == "sprite300" || name == "sprite301" || name == "sprite302" || name == "sprite303" || name == "sprite304"
			|| name == "sprite305" || name == "sprite306" || name == "sprite307"){
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
	m_Sprite->setTextureRect(values[6]);
	m_Border = m_Sprite->getGlobalBounds();
	m_Sprite->setPosition(250, 250);
	m_Sprite->setRotation(0.0f);
	

	m_Collider = new Core::ColliderComponent("Collider");
	m_Collider->setLocalBounds(m_Sprite->getGlobalBounds());
	m_Collider->setCollisionListener(this);
	attachComponent(m_Collider);

	auto inputController = new PlayerInputController("PlayerInput");
	attachComponent(inputController);

	auto movement = new AirplaneSupportMovement("PlayerMovement");
	attachComponent(movement);

	auto renderer = new Core::RendererComponent("PlayerSprite");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

	auto spriteAnimation = new LionAnimation("Charlie");
	attachComponent(spriteAnimation);
	
	Core::PhysicsManager::getInstance()->trackObject(m_Collider);
}

void Player::OnCollisionEnter(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		m_ColliderActive = true;
		
	}
}

void Player::OnCollisionExit(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		m_ColliderActive = false;
		
	}
}

void Player::OnCollisionStay(Entity* entity)
{
	if (entity->getName().find("Floor") != std::string::npos)
	{
		m_ColliderActive = true;
		//m_Velocity.y = 0.0f;
		//m_Acceleration.y = 0.0f;
		//float overlap = this->m_Transformable.getPosition().y + this->m_Border.height - entity->m_Position.y;

		// Move the player up by the amount of overlap to ensure it's on top of the floor
		//if (overlap > 0)
		//{
		//	this->m_Transformable.move(0.0f, -overlap);
		//}
	}
}


