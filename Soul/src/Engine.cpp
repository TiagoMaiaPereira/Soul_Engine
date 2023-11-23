#include "spch.h"

namespace Soul 
{
	void Engine::Initialize(const char* title, int width, int height)
	{
		if (SDL_INIT_VIDEO != 0)
		{
			std::cout << "[ERROR]: SDL_VIDEO not initialized! \n\n" << std::endl;
		}

		std::cout << "Soul is starting...\n" << std::endl;

		std::cout << "Title: " << title << std::endl;
		std::cout << "Window width: " << width << std::endl;
		std::cout << "Window height: " << height << std::endl;
	}

	void Engine::HandleEvents()
	{
		while (isRunning) {

		}
	}

	void Engine::Clear()
	{

	}

}