#pragma once


#ifdef BASE_PLATFORM_WINDOWS
	extern Core::Core* Core::CreateApplication();

	int main(){
		
		auto app = Core::CreateApplication();
		app->Run();
		delete app;

	}
#endif