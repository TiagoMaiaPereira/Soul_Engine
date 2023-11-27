#pragma once
#include "spch.h"

namespace Soul {

	class SDLWindow
	{
	public:
		SDLWindow(const char* title, int width, int height);

		~SDLWindow();

		SDL_Window* getWindow() const { return window; }

	private:
		SDL_Window* window = nullptr;
	};

}

