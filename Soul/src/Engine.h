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

		void StopRunning();
		
		bool IsRunning() { return isRunning; }

		static Engine& getEngine() { return *instance; }

	private:

		static Engine* instance;

		bool isRunning = false;

	};

}