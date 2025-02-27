#include "Builder.h"
#include "Core/EntryPoint.h"
#include "GameLayer.h"
//THIS IS THE ACTUAL APPLICATION OR GAME
class App : public Core::Core{
public:
	App() {
		std::cout << "Application";	
		PushLayer(new GameLayer());
		//PushOverlay(new UI());
	}

	~App() {

	}
};

Core::Core* Core::CreateApplication() {
	return new App();
}
