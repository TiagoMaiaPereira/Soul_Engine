#pragma once
#include "spch.h"

namespace Soul 
{
	class Engine {
	public:

		Engine();

		~Engine();

		void Initialize(const char* title, int width, int height);

		void Run();

		void HandleEvents();

		void StopRunning();

		void Clean();
		
		bool IsRunning() { return isRunning; }

		static Engine* getEngine() { return instance; }

	private:

		static Engine* instance;


		float previousTime = 0;
		float currentTime = 0;
		float frameTime = 0;

		float deltaTime = 0;

		bool isRunning = false;

		SDL_Window* window = nullptr;

		SDL_Event event;


	};

}