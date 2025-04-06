#include "TitleScreen.h"
#include<dos.h>   //for delay()

TitleScreen::TitleScreen(const std::string& name) : Core::Entity(name) , IButtonListener()
{
}

TitleScreen::~TitleScreen()
{
	LOG("TITLE DELETED");
}

void TitleScreen::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("TitleScreen"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	m_Sprite->setPosition(Core::Core::Get().GetWindow().GetWidth()/2, Core::Core::Get().GetWindow().GetHeight() / 2);
	m_Sprite->setScale(0.2, 0.2);

	auto renderer = new Core::RendererComponent("TitleBG");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);


	std::shared_ptr<sf::Texture> normalButton = TextureManager::getInstance()->getTexture("b_4");

	std::shared_ptr<sf::Texture> pressedButton = TextureManager::getInstance()->getTexture("b_5");

	auto button1 = new UIButton("button_1", normalButton, pressedButton);
	attachChild(button1);
	float posX = (float)Core::Core::Get().GetWindow().GetWidth() / 2;
	float posY = (float)Core::Core::Get().GetWindow().GetHeight() / 4 * 3;
	button1->setPosition(posX, posY - 50);
	button1->getTransformable()->setScale(0.3f, 0.3f);
	button1->setButtonListener(this);

	auto button1Text = new UIText("text_1");
	button1->attachChild(button1Text);
	button1Text->setPosition(0, -20);
	button1Text->setSize(100);
	button1Text->setText("PLAY");

	auto button2 = new UIButton("button_2", normalButton, pressedButton);
	attachChild(button2);
	button2->setPosition(posX, posY + 50);
	button2->getTransformable()->setScale(0.3f, 0.3f);
	button2->setButtonListener(this);

	auto button2Text = new UIText("text_2");
	button2->attachChild(button2Text);
	button2Text->setPosition(0, -20);
	button2Text->setSize(100);
	button2Text->setText("QUIT");

	SFXManager::getInstance()->stop();
}

void TitleScreen::OnButtonClick(UIButton* button)
{
	SFXManager::getInstance()->play("Click");
}

void TitleScreen::OnButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1") {
		LOG("CLICK");
		Core::Core::Get().ResumeApplication();
		Core::SceneManager::getInstance()->loadScene(Core::SceneManager::GAME_SCENE_NAME);
	}
	if (button->getName() == "button_2") {
		Core::Core::Get().ApplicationQuit();
	}
}
