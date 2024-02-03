#pragma once
#include "spch.h"
#include "Renderer.h"

namespace Soul 
{
	class GameLevel;

	class Engine {
	public:

		Engine();

		~Engine();

		void Initialize(const char* title, int width, int height);

		void Run();

		void HandleEvents();

		void Render();

		void StopRunning();

		void Clean();
		
		bool IsRunning() { return isRunning; }

		static Engine* getEngine() { return instance; }

		GameLevel& getLevel() { return *world; }

	private:

		static Engine* instance;


		float previousTime = 0;
		float currentTime = 0;
		float frameTime = 0;


		bool isRunning = false;

		SDL_Window* window = nullptr;

		SDL_Texture* testTexture = nullptr;

		SDL_Event event;

		GameLevel *world = nullptr;
	};

}