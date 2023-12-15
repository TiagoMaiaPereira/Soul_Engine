#pragma once
#include "spch.h"

namespace Soul 
{
	class Engine {
	public:

		void Initialize();

		void StopRunning();
		
		bool IsRunning() { return isRunning; }

		static Engine& getEngine() { return *instance; }

	private:

		static Engine* instance;

		bool isRunning = false;


	};

}