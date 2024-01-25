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
		
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "[ERROR]: SDL_Video not initialized..." << std::endl;
			return;
		}
		std::cout << "Subsystems initialized!" << std::endl;

		//Create window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (window == nullptr) {
			std::cout << "[ERROR]: Window could not be created..." << std::endl;

			SDL_Quit();
			return;
		}
		std::cout << "Window created!" << std::endl;

		//Initialize Renderer
		Renderer::Init(window);
		std::cout << "Renderer initialized!" << std::endl;

		testTexture = Renderer::LoadTexture("Assets/galaxy2.bmp");
		

		//End init
		std::cout << "Soul has started! \n" << std::endl;
		
	}

	void Engine::Run() 
	{
		isRunning = true;

		while (isRunning) //Game Loop
		{
			currentTime = (float)SDL_GetTicks();
			float deltaTime = (currentTime - previousTime) / 1000.f;
			previousTime = currentTime;

			frameTime += deltaTime;

			HandleEvents();

			//GameWorld Refresh
			//PhysWorld Update
			//Game World Update

			Render();

		}
	}

	void Engine::HandleEvents()
	{
		while (SDL_PollEvent(&event)) //Event Loop
		{
			if (event.type == SDL_QUIT)
				StopRunning();
			else if (event.type == SDL_KEYDOWN) 
			{
				switch (event.key.keysym.sym) {
				case SDLK_a:
					std::cout << "The A key was pressed!" << std::endl;
					break;

				case SDLK_d:
					std::cout << "The D key was pressed!" << std::endl;
					break;

				case SDLK_w:
					std::cout << "The W key was pressed!" << std::endl;
					break;

				case SDLK_s:
					std::cout << "The S key was pressed!" << std::endl;
					break;

				case SDLK_SPACE:
					std::cout << "The Space Bar was pressed!" << std::endl;
					break;

				default:
					break;
				}
			}
		}

		
	}

	void Engine::Render()
	{
		SDL_RenderClear(Renderer::GetRenderer());
		SDL_RenderCopy(Renderer::GetRenderer(), testTexture, NULL, NULL);
		SDL_RenderPresent(Renderer::GetRenderer());
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
		SDL_DestroyRenderer(Renderer::GetRenderer());
	}

	Engine::Engine(){}

	Engine::~Engine(){}
}