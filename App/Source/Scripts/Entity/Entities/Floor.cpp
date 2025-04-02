#include "Floor.h"

 Floor::Floor(const std::string& name) : EmptyEntity(name), CollisionListener()
 {
     
 }

Floor::~Floor()
{
  //Core::PhysicsManager::getInstance()->untrackObject(m_Collider);
}

void Floor::initialize()
 {
  
  sf::FloatRect bounds = sf::FloatRect(0, 450, 640, 200);
  rect = std::make_shared<sf::RectangleShape>();
  rect->setPosition(bounds.left, bounds.top);      // Set position
  rect->setSize({bounds.width, bounds.height});   // Set size
  rect->setFillColor(sf::Color::Transparent);     // No fill (transparent)
  rect->setOutlineColor(sf::Color::White);          // Red outline
  rect->setOutlineThickness(12);
  
  auto renderer = new Core::RendererComponent("Renderer");
  renderer->assignDrawable(rect);
  attachComponent(renderer);
 
  m_Collider = new Core::ColliderComponent("FloorCollider");
  m_Collider->setLocalBounds(bounds);
  m_Collider->setCollisionListener(this);
  attachComponent(m_Collider);

  Core::PhysicsManager::getInstance()->trackObject(m_Collider);
 }

void Floor::OnCollisionEnter(Entity* entity)
{
}

void Floor::OnCollisionExit(Entity* entity)
{
}

