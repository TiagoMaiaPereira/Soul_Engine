#include "spch.h"

namespace Soul 
{
	Engine* Engine::instance;

	void Engine::Initialize(const char* title, int width, int height)
	{

		//Initialize subsystems
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
		instance = this;
		std::cout << "Soul is starting...\n" << std::endl;
		

		//Create window
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "[ERROR]: SDL_Video not initialized..." << std::endl;
			return;
		}

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (window == nullptr) {
			std::cout << "[ERROR]: Window could not be created..." << std::endl;

			SDL_Quit();
			return;
		}

		std::cout << "Soul has started! \n" << std::endl;
		
	}

	void Engine::Run() 
	{
		isRunning = true;

		while (isRunning) 
		{
			HandleEvents();

			keyState = SDL_GetKeyboardState(NULL);

			if (keyState[SDL_SCANCODE_A])
				std::cout << "The A key was pressed!" << std::endl;

			if (keyState[SDL_SCANCODE_D])
				std::cout << "The D key was pressed!" << std::endl;
		}
	}

	void Engine::HandleEvents()
	{
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				StopRunning();
		}

		
	}

	void Engine::StopRunning() 
	{ 
		isRunning = false;
		std::cout << "Soul is shutting down..." << std::endl;
		
	}

	void Engine::Clean() 
	{
		if (window != nullptr) {
			SDL_DestroyWindow(window);
			window = nullptr;
		};
	}

	Engine::Engine(){}

	Engine::~Engine(){}
}