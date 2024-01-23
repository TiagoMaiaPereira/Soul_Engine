#include "spch.h"

namespace Soul 
{
	Engine* Engine::instance;

	SpriteRenderer *Sprenderer;

	void Engine::Initialize(unsigned int width, unsigned int height)
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
		isRunning = true;
		instance = this;
		std::cout << "Soul is starting...\n" << std::endl;

		Renderer::LoadShader("Shaders/spritevertex.shader","Shaders/spritefrag.shader",nullptr,"sprite");

		glm::mat4 projection = glm::ortho(0.0f,static_cast<float>(width), static_cast<float>(height), 0.f,-1.f, 1.f);
		Renderer::GetShader("sprite").Use().SetInteger("image", 0);
		Renderer::GetShader("sprite").SetMatrix4("projection", projection);

		Shader spShader = Renderer::GetShader("sprite"); 
		Sprenderer = new SpriteRenderer (spShader);
		Renderer::LoadTexture("Resources/graphics/bblogo.bmp",true,"logo");

	}

	void Engine::StopRunning() 
	{ 
		std::cout << "Soul is shutting down..." << std::endl;
		isRunning = false; 
	}

	void Engine::Update(float dt)
	{

	}

	void Engine::Render()
	{

	}


}