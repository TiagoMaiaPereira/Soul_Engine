#include "spch.h"
namespace Soul {

	SDLWindow::SDLWindow(const char* title, int width, int height)
		:window(nullptr)
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "[ERROR]: SDL_Video not initialized!!!!!" << std::endl;
			return;
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); 
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); 
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); 
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8); 

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL); 
		if (window == nullptr) {
			std::cout << "[ERROR]: Window could not be created!" << std::endl;

			SDL_Quit();
			return;
		}

		context = SDL_GL_CreateContext(window);

		if (context == nullptr) {
			std::cout << "[ERROR]: OpenGL context could not be created!" << std::endl;
			SDL_Quit(); 
			return;
		}

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;

			SDL_Quit();
			return;
		} 
	}

	SDLWindow::~SDLWindow()
	{
		if (window != nullptr) {
			SDL_DestroyWindow(window);
			window = nullptr;
		}
		if (context != nullptr)
		{
			SDL_GL_DeleteContext(context);
			context = nullptr;
		}

		SDL_Quit();
	}
}
