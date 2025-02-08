#include "GameLayer.h"
#define LOG(x) std::cout<< x << std::endl
GameLayer::GameLayer() : Layer("Layer") 
{
	
}

GameLayer::~GameLayer()
{
	SFXManager::getInstance()->deleteResources();
	delete SFXManager::getInstance();
	delete TextureManager::getInstance();
	delete EntityManager::getInstance();
}

void GameLayer::OnAttach()
{
	srand(time(nullptr));
	TextureManager::getInstance()->loadAll();

	m_ActiveScene = std::make_shared<Core::Scene>();

	BGObject* bgObject = new BGObject("BGObject");
	EntityManager::getInstance()->addEntity(bgObject);

	Player* player = new Player("Player");
	EntityManager::getInstance()->addEntity(player);

	AirplaneSupport* support1 = new AirplaneSupport("support1");
	player->attachChild(support1);
	support1->setPosition(50, 100);

	AirplaneSupport* support2 = new AirplaneSupport("support2");
	player->attachChild(support2);
	support2->setPosition(-50, 100);

	Core::EmptyEntity* enemiesManager = new Core::EmptyEntity("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(200, "swarmHandler", enemiesManager);
	enemiesManager->attachComponent(swarmHandler);
	EntityManager::getInstance()->addEntity(enemiesManager);

	if (!m_Font.loadFromFile("Media/Sansation.ttf")) {
		LOG("Cannot open File");
	}
	m_TextTimeUpdate.setFont(m_Font);
	m_TextTimeUpdate.setCharacterSize(36);
	m_TextTimeUpdate.setFillColor(sf::Color::White);
	m_TextTimeUpdate.setPosition(0.f, 40.f);

	m_TextFramePerSeconds.setFont(m_Font);
	m_TextFramePerSeconds.setCharacterSize(36);
	m_TextFramePerSeconds.setFillColor(sf::Color::White);

	SFXManager::getInstance()->loadAll();

}

void GameLayer::OnRemove()
{
}

void GameLayer::OnUpdate(sf::Time timestep)
{

	Update(timestep);

	Render();
}

void GameLayer::OnEvent(sf::Event& e)
{
	//PROBLEM
	EntityManager::getInstance()->processInput(e);
	switch (e.type) {

	//case sf::Event::MouseButtonPressed:
	//	LOG(Core::Input::GetMousePosition().first);
	//	handleMouseInputs(e.mouseButton.button, true);
	//	break;
	//case sf::Event::MouseButtonReleased:
	//	handleMouseInputs(e.mouseButton.button, false);
	//	break;
	case sf::Event::KeyPressed:
		playSFX();
		/*if (Core::Input::IsKeyPressed(sf::Keyboard::Space)) {
				EntityManager::getInstance()->addEntity(new EnemyAirplane("Avenger"));
		}*/
		break;
	}
	
}

void GameLayer::Update(sf::Time timestep)
{
	std::string timeFramePerSecond = "Frames / Second = " + std::to_string((int)(1.0f / timestep.asSeconds()));
	m_TextFramePerSeconds.setString(timeFramePerSecond);

	std::string timeUpdate = "Time/Update: " + std::to_string(timestep.asMicroseconds()) + "us";
	m_TextTimeUpdate.setString(timeUpdate);

	//Update scene
	m_ActiveScene->OnUpdate(timestep);

	//PROBLEM
	EntityManager::getInstance()->update(timestep);
}

void GameLayer::handleMouseInputs(sf::Mouse::Button button, bool isPressed)
{
	switch (button) {
	case sf::Mouse::Left:
		m_MouseLeftButton = isPressed;
		break;
	}
}

void GameLayer::Render()
{
	Core::RenderCommand::Clear();
	Core::Renderer::StartScene();
	EntityManager::getInstance()->render();
	Core::Renderer::Enter(m_TextTimeUpdate);
	Core::Renderer::Enter(m_TextFramePerSeconds);
	Core::Renderer::EndScene();
}

void GameLayer::playSFX()
{
	if (Core::Input::IsKeyPressed(sf::Keyboard::Num1)) {		
		SFXManager::getInstance()->play("SFX_1");
	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::Num2))
		SFXManager::getInstance()->play("SFX_2");
	if (Core::Input::IsKeyPressed(sf::Keyboard::Num3))
		SFXManager::getInstance()->play("SFX_3");
	if (Core::Input::IsKeyPressed(sf::Keyboard::Num4))
		SFXManager::getInstance()->play("SFX_4");
}
