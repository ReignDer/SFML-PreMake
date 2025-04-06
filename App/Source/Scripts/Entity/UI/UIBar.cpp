#include "UIBar.h"

UIBar::UIBar(const std::string& name) : Core::Entity(name), IButtonListener()
{
}

void UIBar::initialize()
{
	m_Sprite = std::make_shared<sf::Sprite>();
	m_Sprite->setTexture(*TextureManager::getInstance()->getTexture("bar_1"));
	sf::Vector2u textureSize = m_Sprite->getTexture()->getSize();
	m_Sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	m_Sprite->setScale(0.125, 0.15);

	auto renderer = new Core::RendererComponent("UIBar");
	renderer->assignDrawable(m_Sprite);
	attachComponent(renderer);

	float posX = Core::Core::Get().GetWindow().GetWidth()  / 2;
	float posY = Core::Core::Get().GetWindow().GetHeight() / 10;

	setPosition(posX, posY);
	this->m_Transformable.setScale(sf::Vector2f(1.f, 1.f));

	std::shared_ptr<sf::Texture> normalButton = TextureManager::getInstance()->getTexture("b_4");

	std::shared_ptr<sf::Texture> pressedButton = TextureManager::getInstance()->getTexture("b_5");

	auto button1 = new UIButton("button_1", normalButton, pressedButton);
	attachChild(button1);
	button1->setPosition(160, posY * 8);
	button1->getTransformable()->setScale(0.18f, 0.18f);
	button1->setButtonListener(this);

	auto button1Text = new UIText("text_1");
	button1->attachChild(button1Text);
	button1Text->setPosition(0, -20);
	button1Text->setSize(100);
	button1Text->setText("QUIT");



	auto scoreText = new UIText("score");
	attachChild(scoreText);
	scoreText->setPosition(-150, 0);
	scoreText->setSize(20);
	scoreText->setText("SCORE-00000");

	auto scoreCounter = new ScoreCounter("scc", scoreText);
	attachComponent(scoreCounter);

	auto bonusText  = new UIText("bonus");
	attachChild(bonusText);
	bonusText->setPosition(0, 0);
	bonusText->setSize(20);
	bonusText->setText("TIME-00:00");

	auto bonusCounter = new BonusCounter("bc", bonusText);
	attachComponent(bonusCounter);

	auto stageText = new UIText("stage");
	attachChild(stageText);
	stageText->setPosition(150, 0);
	stageText->setSize(20);
	stageText->setText("Stage-01");

	auto stageCounter = new StageCounter("stc", stageText);
	attachComponent(stageCounter);

	//std::shared_ptr<sf::Texture> lifetexture = TextureManager::getInstance()->getTexture("life");
	//auto button1 = new UIButton("lc", lifetexture, pressedButton);
}

void UIBar::OnButtonClick(UIButton* button)
{
	SFXManager::getInstance()->play("Click");
	Core::EntityManager::getInstance()->findObjectByName("MainMenuScreen")->setEnabled(true);
	Core::Core::Get().PauseApplication();
}

void UIBar::OnButtonReleased(UIButton* button)
{
}
