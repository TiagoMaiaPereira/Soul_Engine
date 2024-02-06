#pragma once


namespace Soul 
{
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

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual float GetWidthF() const = 0;
		virtual float GetHeightF() const = 0;

		virtual void Bind(uint32_t slot = 0) const = 0;

		virtual bool operator==(const Texture& other) const = 0;

	};

	class Texture2D : public Texture
	{

	public:

		static std::shared_ptr<Texture2D> Create(const std::string& path);

		void CreateAndLoadRects(TextureData rect, TextureData posRect);

		void LoadPosRect(TextureData* posRect);
		void LoadRects(TextureData* rect, TextureData* posRect);
		void SetTextColor(glm::vec4 color);
		void ClearTextColor();

	public:
		SDL_FRect* destRect;
		SDL_FRect* srcRect;
		int t_PixelSize;
		glm::vec2 t_Size;
	};
}


