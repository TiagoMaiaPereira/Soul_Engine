#pragma once
#include "spch.h"

namespace Soul {

	class Window
	{
	public:
		Window(const char* title, int width, int height);

		~Window();

		SDL_Window* getWindow() const { return window; }

		void createWindow();

		void destroyWindow();

	private:
		SDL_Window* window = nullptr;
	};

}

