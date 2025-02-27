#include "GameLayer.h"

GameLayer::GameLayer() : Layer("Layer") 
{
	
}

GameLayer::~GameLayer()
{
	SFXManager::getInstance()->deleteResources();
	delete SFXManager::getInstance();
	delete TextureManager::getInstance();
	delete Core::EntityManager::getInstance();
	delete FontManager::getInstance();
	delete ObjectPoolHolder::getInstance();
}

void GameLayer::OnAttach()
{
	srand(time(nullptr));

	m_ActiveScene = std::make_shared<Core::Scene>();

	Core::SceneManager::getInstance()->registerScene(new GameLayerScene);
	Core::SceneManager::getInstance()->registerScene(new TitleScene);
	Core::SceneManager::getInstance()->registerScene(new MainMenuScene);
	Core::SceneManager::getInstance()->loadScene(Core::SceneManager::TITLE_SCENE_NAME);



	//Core::SceneManager::getInstance()->loadScene(Core::SceneManager::MAIN_MENU_SCENE_NAME);
	


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

	Core::SceneManager::getInstance()->checkLoadScene();
}

void GameLayer::OnEvent(sf::Event& e)
{
	//PROBLEM
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
	default:
		Core::EntityManager::getInstance()->processInput(e);
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
	if (!Core::Core::Get().isPaused())
		Core::EntityManager::getInstance()->update(timestep);
	else
		Core::EntityManager::getInstance()->update(sf::Time::Zero);
	
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
	Core::EntityManager::getInstance()->render();
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
