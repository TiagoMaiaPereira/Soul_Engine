#include "spch.h"
#include "Texture.h"
#include "GLTexture.h"

namespace Soul
{

	std::shared_ptr<Texture2D> Texture2D::Create(const std::string& path)
	{
		return std::make_shared<GLTexture>(path);
	}


	void Texture2D::CreateAndLoadRects(TextureData src, TextureData dest)
	{
		destRect = new SDL_FRect();
		srcRect = new SDL_FRect();

		srcRect->x = src.dataX;
		srcRect->y = src.dataY;
		srcRect->w = src.dataW;
		srcRect->h = src.dataH;

		destRect->x = dest.dataX;
		destRect->y = dest.dataY;
		destRect->w = dest.dataW;
		destRect->h = dest.dataH;
	}

	void Texture2D::LoadRects(TextureData* rect, TextureData* posRect)
	{
		srcRect->x = rect->dataX;
		srcRect->y = rect->dataY;
		srcRect->w = rect->dataW;
		srcRect->h = rect->dataH;

		destRect->x = posRect->dataX;
		destRect->y = posRect->dataY;
		destRect->w = posRect->dataW;
		destRect->h = posRect->dataH;
	}

	void Texture2D::SetTextColor(glm::vec4 color)
	{
	}

	void Texture2D::ClearTextColor()
	{
	}

	void Texture2D::LoadPosRect(TextureData* posRect) {
		destRect->x = posRect->dataX;
		destRect->y = posRect->dataY;
		destRect->w = posRect->dataW;
		destRect->h = posRect->dataH;
	}
}
