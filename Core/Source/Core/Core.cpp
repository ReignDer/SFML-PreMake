#include "Corepch.h"
#include "Core.h"
#include <SFML/Graphics.hpp>
//THIS IS THE STATIC LIBRARY

namespace Core {

    Core* Core::s_Instance = nullptr;

    Core::Core() {
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        RenderCommand::setWindow(*m_Window->GetNativeWindow());
 
        /* sf::RenderWindow window(sf::VideoMode(500, 500), "Mathieu Marc I. Pobre");
         window.setFramerateLimit(60.f);*/
    }

    Core::~Core() {

    }

    void Core::OnUpdate(sf::Event& e)
    {
        //TODO: MAKE EVENT DISPATCHER

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if (e.type == sf::Event::Closed) {
                m_Running = false;
                break;
            }
            
            
        }
    }


    void Core::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Core::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }



    void Core::Run() {

        sf::Clock clock;
        sf::Event event;
        while (m_Running) {

            sf::Time time = clock.getElapsedTime();
            sf::Time timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;


            for (Layer* layer : m_LayerStack) {
                layer->OnUpdate(timestep);
            }

            /*TEMPORARY SETUP FOR POLLING AND EVENTS*/
            sf::Event event;
            while (m_Window->GetNativeWindow()->pollEvent(event)) {
                OnUpdate(event);

            }

            //TODO: PUT POLLING HERE
            m_Window->OnUpdate();
           
            /*m_Window->clear();
            m_Window->draw(shape);
            m_Window->display();*/

        }
    }

    //TO DO: NEEDS OBSERVER 
    bool Core::OnWindowClosedEvent(sf::Event& e)
    {
        m_Running = false;
        return true;
    }

}
