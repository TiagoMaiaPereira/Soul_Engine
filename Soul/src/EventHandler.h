#pragma once
#include "spch.h"

namespace Soul {

	class EventHandler
	{
	public:
		EventHandler();

		virtual ~EventHandler();

		void handleEvents();

		virtual void onQuit();

	};
}

