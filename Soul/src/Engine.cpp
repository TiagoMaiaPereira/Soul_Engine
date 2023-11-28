#include "spch.h"

namespace Soul 
{
	Engine* Engine::instance;

	void Engine::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
		isRunning = true;
		instance = this;
		std::cout << "Soul is starting...\n" << std::endl;
	}

	void Engine::StopRunning() 
	{ 
		std::cout << "Soul is shutting down..." << std::endl;
		isRunning = false; 
	}


}