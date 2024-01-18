#include "spch.h"

namespace Soul {

	Window::Window(const char* title, int width, int height)
	{
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
	}

	void Window::createWindow()
	{
		
	}

	void Window::destroyWindow()
	{
		if (window != nullptr) {
			SDL_DestroyWindow(window);
			window = nullptr;
		};
	}

	Window::~Window()
	{
	}
}
