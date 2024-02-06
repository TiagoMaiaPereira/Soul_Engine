#pragma once
#include "Texture.h"
#include "Renderer.h"

namespace Soul 
{
	class GameLevel;
	class PhysWorld;

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

		SDL_Event event;

		GameLevel *world = nullptr;

		PhysWorld* physWorld = nullptr;

		std::shared_ptr<Texture2D> textures;


		glm::mat4 triangle_transformMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3, 0.3, 0));
	};

}