#pragma once
#include "spch.h"


namespace Soul {
	
	struct Texture;

	class Renderer{
	public:

		static void Init(SDL_Window* window);

		static SDL_Texture* LoadTexture(std::string filePath);

		static SDL_Renderer* GetRenderer() { return renderTarget; }


		static void RenderTexture(Texture& text);


	private:
		static SDL_Renderer* renderTarget;

	};

	

