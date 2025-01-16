#include "Builder.h"
#include "Entity.h"

//THIS IS THE ACTUAL APPLICATION OR GAME
#define LOG(x) std::cout<< x << std::endl
class GameLayer : public Core::Layer {

public:

	GameLayer()
		: Layer("Layer"){
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
		m_TextTimeUpdate.setPosition(0.f,40.f);
		
		m_TextFramePerSeconds.setFont(m_Font);
		m_TextFramePerSeconds.setCharacterSize(36);
		m_TextFramePerSeconds.setFillColor(sf::Color::White);
		

	}
	virtual void OnUpdate(sf::Time timestep) override {
		
		Update(timestep);
		
		Render();
	}

	virtual void OnEvent(sf::Event& e) override {
		switch (e.type) {
			case sf::Event::KeyPressed:
				handleInputs(e.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handleInputs(e.key.code, false);
				break;
			case sf::Event::MouseButtonPressed:
				LOG(Core::Input::GetMousePosition().first);
				handleMouseInputs(e.mouseButton.button, true);
				break;
			case sf::Event::MouseButtonReleased:
				handleMouseInputs(e.mouseButton.button, false);
				break;
		}
	}

private:
	Entity m_Player;
	sf::Text m_TextTimeUpdate;
	sf::Text m_TextFramePerSeconds;
	sf::Font m_Font;

	bool m_IsMovingUp = false;
	bool m_IsMovingDown = false;
	bool m_IsMovingLeft = false;
	bool m_IsMovingRight = false;

	bool m_MouseLeftButton = false;
	
	float m_PlayerSpeed = 300.f;
private:
	void Update(sf::Time timestep) {
		
		std::string timeFramePerSecond = "Frames / Second = " + std::to_string((int)(1.0f / timestep.asSeconds()));
		m_TextFramePerSeconds.setString(timeFramePerSecond);

		std::string timeUpdate = "Time/Update: " + std::to_string(timestep.asMicroseconds()) + "us";
		m_TextTimeUpdate.setString(timeUpdate);

		sf::Vector2f movement(0.f, 0.f);

		if (m_IsMovingUp) {
			movement.y -= 1;
			
		}
		if (m_IsMovingDown) {
			movement.y += 1;
			
		}
		if (m_IsMovingRight) {
			movement.x += 1;
			
		}
		if (m_IsMovingLeft) {
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

		
		if(movement != sf::Vector2f(0.0f,0.0f))
			m_Player.GetSprite()->setRotation(angle);

	}
	void handleMouseInputs(sf::Mouse::Button button, bool isPressed) {
		switch (button) {
			case sf::Mouse::Left:
				m_MouseLeftButton = isPressed;
				break;
		}
	}

	void Render() {
		Core::RenderCommand::Clear();
		Core::Renderer::StartScene();
		Core::Renderer::Enter(*m_Player.GetSprite());
		Core::Renderer::Enter(m_TextFramePerSeconds);
		Core::Renderer::Enter(m_TextTimeUpdate);
		Core::Renderer::EndScene();
	}

	void handleInputs(sf::Keyboard::Key key, bool isPressed) {
		switch (key) {
			case (sf::Keyboard::W):
				m_IsMovingUp = isPressed;
				break;
			case (sf::Keyboard::A): 
				m_IsMovingLeft = isPressed;
				break;
			
			case (sf::Keyboard::S): 
				m_IsMovingDown = isPressed;
				break;
			
			case (sf::Keyboard::D):
				m_IsMovingRight = isPressed;
				break;
			
		}
	}
};

class App : public Core::Core{
public:
	App() {
		std::cout << "Application";	
		PushLayer(new GameLayer);
		

	}

	~App() {

	}
};

Core::Core* Core::CreateApplication() {
	return new App();
}
