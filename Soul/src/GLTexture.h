#pragma once
#include"Texture.h"

namespace Soul
{
	class GLTexture : public Texture2D
	{
	public:
		GLTexture(const std::string& path);
		GLTexture(const std::string& path, TextureData rect, TextureData posRect);
		virtual ~GLTexture();

		virtual uint32_t GetWidth() const override { return  m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; };

		virtual float GetWidthF() const override { return (float)m_Width; };
		virtual float GetHeightF() const override { return (float)m_Height; };

		virtual void Bind(uint32_t slot = 0) const override;

		virtual bool operator==(const Texture& other) const override { return m_RendererID == ((GLTexture&)other).m_RendererID; }
	private:
		void LoadTexture(const std::string& path);

	private:
		uint32_t m_RendererID = 0;
		std::string m_Path;
		uint32_t m_Width;
		uint32_t m_Height;
	};
}