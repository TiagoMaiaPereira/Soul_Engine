#include "Renderer.h"
#include "spch.h"


Renderer* Renderer::instance;

Renderer::Renderer(SDL_Window* window, SDL_GLContext glContext)
{
	instance = this;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2); 
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8); 

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		SDL_Quit();
	}
}
