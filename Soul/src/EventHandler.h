#pragma once
#include "spch.h"

namespace Soul {

	class EventHandler
	{
	public:
		EventHandler();

		virtual ~EventHandler();

		void handleEvents(float dt);

		bool Keys[1024];

		virtual void onQuit();

	};
}

