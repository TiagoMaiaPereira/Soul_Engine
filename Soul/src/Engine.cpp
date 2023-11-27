#include "spch.h"

namespace Soul 
{
	void Engine::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

		std::cout << "Soul is starting...\n" << std::endl;
	}

}