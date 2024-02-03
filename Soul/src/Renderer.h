#pragma once
#include "spch.h"


namespace Soul {
	
	class Renderer{
	public:

		static void Init(SDL_Window* window);

		static SDL_Texture* LoadTexture(std::string filePath);

		static SDL_Renderer* GetRenderer() { return renderTarget; }


		static void RenderTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);


	private:
		static SDL_Renderer* renderTarget;

	};
}

