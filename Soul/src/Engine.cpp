#include "spch.h"

namespace Soul 
{
	Engine* Engine::instance;

	void Engine::Initialize(const char* title, int width, int height)
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
		isRunning = true;
		instance = this;
		std::cout << "Soul is starting...\n" << std::endl;
		
		Window window(title, width, height);

		std::cout << "Soul has started! \n" << std::endl;
		
	}

	void Engine::Run() 
	{
	}

	void Engine::StopRunning() 
	{ 
		std::cout << "Soul is shutting down..." << std::endl;
		isRunning = false;
		
	}

	Engine::Engine(){}

	Engine::~Engine(){}
}