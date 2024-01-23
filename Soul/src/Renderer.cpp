#include "spch.h"

namespace Soul {

	SDL_Renderer* Renderer::renderTarget;

	void Renderer::Init(SDL_Window* window)
	{
		if (window != nullptr)
		{
			renderTarget = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (renderTarget == nullptr)
			{
				std::cout << "[ERROR]: Failed to create render target! Renderer is null!" << std::endl;
			}
			else
			{
				std::cout << "Renderer created!" << std::endl;
			}
		}
		else
		{
			std::cout << "[ERROR]: Target window is null!" << std::endl;
		}
	}

	SDL_Texture* Renderer::LoadTexture(std::string filePath)
	{

		SDL_Texture* texture = nullptr;
		SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
		if (surface == NULL)
			std::cout << "[Error]: Failed to load the image: " << filePath << std::endl;
		else
		{
			texture = SDL_CreateTextureFromSurface(renderTarget, surface);
			if (texture == NULL)
				std::cout << "Error" << std::endl;
		}
		SDL_FreeSurface(surface);

		return texture;
	}
}