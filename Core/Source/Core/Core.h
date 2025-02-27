#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "LayerStack.h"
#include "Event/EventDispatcher.h"
#include "Renderer/Renderer.h"
#include "Renderer/RenderCommand.h"
#include "Scene/SceneManager.h"

namespace Core {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	//void PrintHelloWorld();
	class Core {
	public:
		Core();

		virtual ~Core();

		void Run();

		void OnUpdate(sf::Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline Window& GetWindow() { return *m_Window; }
		inline static Core& Get() { return *s_Instance; }

		enum CoreState{ Running = 0, Paused = 1 };

		void ApplicationQuit();
		void PauseApplication();
		void ResumeApplication();
		bool isPaused();

	private:
		bool OnWindowClosedEvent(sf::Event& e);

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		
		sf::Time m_LastFrameTime = sf::Time::Zero;

		//TEMPORARY
		sf::Mouse mousePos;

		bool m_Running = true;
		CoreState state;

	private:
		static Core* s_Instance;

	};

	//TO BE DEFINED IN CLIENT
	Core* CreateApplication();
}