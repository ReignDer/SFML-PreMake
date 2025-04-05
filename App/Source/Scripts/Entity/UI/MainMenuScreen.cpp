#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(const std::string& name) : Core::Entity(name), IButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("PopUP"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x/2, textureSize.y / 2);
	m_Sprite->setScale(0.35, 0.3);

	auto renderer = new Core::RendererComponent("MainMenuScreen");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

	float posX = Core::Core::Get().GetWindow().GetWidth() / 2;
	float posY = Core::Core::Get().GetWindow().GetHeight() / 2;

	setPosition(posX, posY);
	this->m_Transformable.setScale(sf::Vector2f(0.7f,0.7f));

	auto TextBox = new UIText("text_1");
	attachChild(TextBox);
	TextBox->setPosition(0, -50);
	TextBox->setSize(50);
	TextBox->setText("Are you sure \n \tyou want to\n \t quit the game?");

	setEnabled(false);

	std::shared_ptr<sf::Texture> normalButton = TextureManager::getInstance()->getTexture("b_4");

	std::shared_ptr<sf::Texture> pressedButton = TextureManager::getInstance()->getTexture("b_5");

	auto button1 = new UIButton("button_1",normalButton, pressedButton);
	attachChild(button1);
	button1->setPosition(-150,120);
	button1->getTransformable()->setScale(0.3f,0.3f);
	button1->setButtonListener(this);

	auto button1Text = new UIText("text_1");
	button1->attachChild(button1Text);
	button1Text->setPosition(0, -20);
	button1Text->setSize(100);
	button1Text->setText("YES");

	auto button2 = new UIButton("button_2", normalButton, pressedButton);
	attachChild(button2);
	button2->setPosition(150, 120);
	button2->getTransformable()->setScale(0.3f, 0.3f);
	button2->setButtonListener(this);

	auto button2Text =  new UIText("text_2");
	button2->attachChild(button2Text);
	button2Text->setPosition(0, -20);
	button2Text->setSize(100);
	button2Text->setText("NO");



 
}

void MainMenuScreen::OnButtonClick(UIButton* button)
{
	SFXManager::getInstance()->play("Click");
}

void MainMenuScreen::OnButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1") {
		
		Core::SceneManager::getInstance()->loadScene(Core::SceneManager::TITLE_SCENE_NAME);
	}
	if (button->getName() == "button_2") {
		Core::Core::Get().ResumeApplication();
		setEnabled(false);
	}
}
