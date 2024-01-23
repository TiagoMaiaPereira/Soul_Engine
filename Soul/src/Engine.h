#pragma once
#include "spch.h"

namespace Soul 
{
	class Engine {
	public:

		void Initialize(unsigned int width, unsigned int height);

		void StopRunning();
		
		bool IsRunning() { return isRunning; }

		static Engine& getEngine() { return *instance; }

		void Update (float dt);

		void Render();

	private:

		static Engine* instance;

		bool isRunning = false;  


	};

}