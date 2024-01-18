#include "spch.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Test Window", 640, 480);

	EventHandler eventHandler;

	while (engine.IsRunning()) { //Game Loop
		eventHandler.handleEvents();//Event Loop
	}


	return 0;
}
