#pragma once
#include "Builder.h"
#include "SFXManager.h"

class GameLayer : public Core::Layer
{
public:

	GameLayer();
	virtual ~GameLayer() = default;
	virtual void OnAttach() override;
	virtual void OnRemove() override;
	virtual void OnUpdate(sf::Time timestep) override;

	virtual void OnEvent(sf::Event& e) override; 

private:
	Core::Entity m_Player;
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
	void Update(sf::Time timestep);
	void handleMouseInputs(sf::Mouse::Button button, bool isPressed); 

	void Render(); 

	void handleMovement(const sf::Time& timestep);
	void playSFX();
};

