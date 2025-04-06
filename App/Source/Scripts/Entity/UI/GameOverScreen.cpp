#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(const std::string& name) : Core::Entity(name), IButtonListener()
{
}

GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::initialize()
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
	TextBox->setText("Game Over!");

	auto HighScore = new UIText("text_2");
	attachChild(TextBox);
	TextBox->setPosition(0, 0);
	TextBox->setSize(30);
	
	std::string text = "High Score: \n";
	int score = GameManager::getInstance()->getHighScore();
	text += std::to_string(score);
	TextBox->setText(text);

	auto Score = new UIText("text_3");
	attachChild(TextBox);
	TextBox->setPosition(0, 50);
	TextBox->setSize(20);

	std::string text = "Score: \n";
	score = GameManager::getInstance()->getPrevScore();
	text += std::to_string(score);
	TextBox->setText(text);

	setEnabled(false);

	std::shared_ptr<sf::Texture> normalButton = TextureManager::getInstance()->getTexture("b_4");

	std::shared_ptr<sf::Texture> pressedButton = TextureManager::getInstance()->getTexture("b_5");

	auto button1 = new UIButton("button_1",normalButton, pressedButton);
	attachChild(button1);
	button1->setPosition(0,120);
	button1->getTransformable()->setScale(0.3f,0.3f);
	button1->setButtonListener(this);

	auto button1Text = new UIText("text_1");
	button1->attachChild(button1Text);
	button1Text->setPosition(0, -20);
	button1Text->setSize(100);
	button1Text->setText("Quit");



 
}

void GameOverScreen::OnButtonClick(UIButton* button)
{
	SFXManager::getInstance()->play("Click");
}

void GameOverScreen::OnButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1") {
		setEnabled(false);
		Core::SceneManager::getInstance()->loadScene(Core::SceneManager::TITLE_SCENE_NAME);
	}
}
