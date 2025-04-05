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
  std::shared_ptr<sf::RectangleShape> rectangle_shape = std::make_shared<sf::RectangleShape>();
  rectangle_shape->setPosition(bounds.left, bounds.top);      // Set position
  rectangle_shape->setSize({bounds.width, bounds.height});   // Set size
  rectangle_shape->setFillColor(sf::Color::Transparent);     // No fill (transparent)
  rectangle_shape->setOutlineColor(sf::Color::White);          // Red outline
  rectangle_shape->setOutlineThickness(12);
  m_Border = bounds;
  
  auto renderer = new Core::RendererComponent("Renderer");
  renderer->assignDrawable(rectangle_shape);
  attachComponent(renderer);
 
  m_Collider = new Core::ColliderComponent("Collider");
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

void Floor::OnCollisionStay(Entity* entity)
{
}


