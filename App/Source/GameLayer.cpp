#include "GameLayer.h"
#define LOG(x) std::cout<< x << std::endl
GameLayer::GameLayer() : Layer("Layer") 
{
		sf::Texture texture;
		if (!texture.loadFromFile("Media/Eagle.png")) {
			LOG("Cannot open File");
		}
		m_Player.SetTexture(texture);
		m_Player.GetSprite()->setOrigin(m_Player.GetSprite()->getLocalBounds().width / 2, m_Player.GetSprite()->getLocalBounds().height / 2);
		m_Player.GetSprite()->setPosition(250, 250);
		m_Player.GetSprite()->setRotation(0.0f);

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

void GameLayer::OnAttach()
{
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
	switch (e.type) {

	case sf::Event::MouseButtonPressed:
		LOG(Core::Input::GetMousePosition().first);
		handleMouseInputs(e.mouseButton.button, true);
		break;
	case sf::Event::MouseButtonReleased:
		handleMouseInputs(e.mouseButton.button, false);
		break;
	case sf::Event::KeyPressed:
		playSFX();
		break;
	}
	
}

void GameLayer::Update(sf::Time timestep)
{
	std::string timeFramePerSecond = "Frames / Second = " + std::to_string((int)(1.0f / timestep.asSeconds()));
	m_TextFramePerSeconds.setString(timeFramePerSecond);

	std::string timeUpdate = "Time/Update: " + std::to_string(timestep.asMicroseconds()) + "us";
	m_TextTimeUpdate.setString(timeUpdate);

	handleMovement(timestep);

	
	
	
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
	Core::Renderer::Enter(*m_Player.GetSprite());
	Core::Renderer::Enter(m_TextFramePerSeconds);
	Core::Renderer::Enter(m_TextTimeUpdate);
	Core::Renderer::EndScene();
}

void GameLayer::handleMovement(const sf::Time& timestep)
{
	sf::Vector2f movement(0.f, 0.f);

	if (Core::Input::IsKeyPressed(sf::Keyboard::W)) {
		movement.y -= 1;

	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::S)) {
		movement.y += 1;

	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::D)) {
		movement.x += 1;

	}
	if (Core::Input::IsKeyPressed(sf::Keyboard::A)) {
		movement.x -= 1;
	}

	if (m_MouseLeftButton) {
		sf::Vector2f mousePos(Core::Input::GetMousePosition().first, Core::Input::GetMousePosition().second);

		movement = mousePos - m_Player.GetSprite()->getPosition();


		movement = movement / std::sqrt(movement.x * movement.x + movement.y * movement.y);

	}

	/*sf::Vector2f up = (sf::Vector2f)sf::Mouse::getPosition() -  m_Player.GetSprite()->getPosition();
	m_Player.GetSprite()->getTransform().transformPoint(up);*/
	sf::Vector2f direction = movement;
	double angle = std::atan2f(movement.x, -movement.y) * 180.0f / 3.14159f;
	m_Player.GetSprite()->move(movement * timestep.asSeconds() * m_PlayerSpeed);


	if (movement != sf::Vector2f(0.0f, 0.0f))
		m_Player.GetSprite()->setRotation(angle);
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
