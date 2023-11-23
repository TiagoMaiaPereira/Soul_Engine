#pragma once
#include "SDL.h"

namespace Soul 
{
	class Engine {
	public:
		void Initialize(const char* title, int width, int height);
		void HandleEvents();
		void Clear();

		
		bool IsRunning() { return isRunning; }

	private:

		bool isRunning;

		SDL_Window* window;
		SDL_Event event;
	};

}