#pragma once
#include "spch.h"

namespace Soul {

	class SDLWindow
	{
	public:
		SDLWindow(const char* title, int width, int height);

		~SDLWindow();

		SDL_Window* getWindow() const { return window; }
		SDL_GLContext getGLContext() const {return context;}

	private:
		SDL_Window* window = nullptr;
		SDL_GLContext context = nullptr;
	};

}

