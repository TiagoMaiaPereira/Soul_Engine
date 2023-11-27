#include "spch.h"

using namespace Soul;

int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize();

	SDLWindow window("Test Window", 640, 480);
	EventHandler eventHandler;

	while (engine.IsRunning()) {
		eventHandler.handleEvents();
	}

	return 0;
}
