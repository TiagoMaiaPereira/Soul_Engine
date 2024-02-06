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

	struct TextureData
	{

		TextureData() = default;
		TextureData(float x, float y, float w, float h)
			:dataX(x), dataY(y), dataW(w), dataH(h)
		{
		}

		SDL_Rect* FillRect(SDL_Rect& rect) 
		{
			rect.x = this->dataX;
			rect.y = this->dataY;
			rect.w = this->dataW;
			rect.h = this->dataH;

			return &rect;
		}

		
		float dataX;
		float dataY;
		float dataW;
		float dataH;
	};

	struct Texture
	{
		Texture() = default;

		Texture(const char* filepath, TextureData rect, TextureData posRect)
		{
			texture = Renderer::LoadTexture(filepath);

			SDL_QueryTexture(texture, NULL, nullptr, &textW, &textH);

			srcRect = new SDL_Rect();
			destRect = new SDL_Rect();

			srcRect->x = rect.dataX;
			srcRect->y = rect.dataY;
			srcRect->w = rect.dataW;
			srcRect->h = rect.dataH;

			destRect->x = posRect.dataX;
			destRect->y = posRect.dataY;
			destRect->w = posRect.dataW;
			destRect->h = posRect.dataH;
		}

		Texture(std::string path)
		{
			texture = Renderer::LoadTexture(path);

			SDL_QueryTexture(texture, NULL, nullptr, &textW, &textH);

			srcRect = 0;
			destRect = 0;
		}

		void LoadRects(TextureData* src, TextureData* dest)
		{
			srcRect->x = src->dataX;
			srcRect->y = src->dataY;
			srcRect->w = src->dataW;
			srcRect->h = src->dataH;

			destRect->x = dest->dataX;
			destRect->y = dest->dataY;
			destRect->w = dest->dataW;
			destRect->h = dest->dataH;

		}

		void LoadRects(TextureData* destPos)
		{
			destRect->x = destPos->dataX;
			destRect->y = destPos->dataY;
			destRect->w = destPos->dataW;
			destRect->h = destPos->dataH;
		}

		SDL_Texture* texture;
		SDL_Rect* srcRect;
		SDL_Rect* destRect;

		int textW;
		int textH;

		operator SDL_Texture* () const { return texture; }
		operator const SDL_Texture* () const { return texture; }
	};
}

