#pragma once
#include "spch.h"

namespace Soul 
{
	class Engine {
	public:
		void Initialize();

		
		bool IsRunning() { return isRunning; }

	private:

		bool isRunning = true;
	};

}