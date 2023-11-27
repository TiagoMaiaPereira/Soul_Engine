#include "spch.h"

namespace Soul {

	EventHandler::EventHandler(){}

	EventHandler::~EventHandler(){}

	void EventHandler::handleEvents() 
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				onQuit();
				break;
			}
		}
	}

	void EventHandler::onQuit() {

		SDL_Quit();
	}
}
