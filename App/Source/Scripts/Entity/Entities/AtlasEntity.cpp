#include "AtlasEntity.h"

AtlasEntity::AtlasEntity(const std::string& name) : Core::Entity(name)
{
}

void AtlasEntity::initialize()
{
    
    //auto renderer = Core::RendererComponent::CreateSprite("AtlasEntity", TextureManager::getInstance()->getTexture("Dota2"));

    m_Sprite = std::make_shared<sf::Sprite>();
    m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("Dota2"));
    sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
    m_Sprite->setOrigin((float)textureSize.x / 2, (float)textureSize.y / 2);
    
	const rapidjson::Document& docs = TextureManager::getInstance()->getDoc();
    doc.CopyFrom(docs,doc.GetAllocator());

    if (doc.HasMember("frames") && doc["frames"].IsObject()) {
        const rapidjson::Value& frames = doc["frames"];

        for (rapidjson::Value::ConstMemberIterator it = frames.MemberBegin(); it != frames.MemberEnd(); it++) {
            const char* name = it->name.GetString();
            const rapidjson::Value& frameValue = it->value;

            LOG(name);
            if (frameValue.HasMember("frame") && frameValue["frame"].IsObject()) {
                const rapidjson::Value& frame = frameValue["frame"];
                int x = frame["x"].GetInt();
                int y = frame["y"].GetInt();
                int w = frame["w"].GetInt();
                int h = frame["h"].GetInt();

                values.emplace_back(x,y,w,h);


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


	m_Sprite->setTextureRect(values[0]);
    
    m_Sprite->setPosition(Core::Core::Get().GetWindow().GetWidth() / 2, Core::Core::Get().GetWindow().GetHeight() / 2);
	auto renderer = new Core::RendererComponent("AtlasEntity");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);


    auto input = new PlayerInputController("Input");
    attachComponent(input);

    auto spriteChange = new SpriteChange("spriteChange");
    attachComponent(spriteChange);


}
