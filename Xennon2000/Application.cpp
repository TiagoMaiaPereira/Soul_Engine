#include "spch.h"
#include "stb_image.h"


using namespace Soul;


int main(int argc, char** argv)
{
	int width = 640;
	int height = 480;
	Engine engine;

	SDLWindow window("Test Window", width, height);

	EventHandler eventHandler;

	engine.Initialize(width, height);

	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;

	while (engine.IsRunning()) { //Game Loop
		
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		

		eventHandler.handleEvents(deltaTime);

		engine.Update(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		engine.Render();
	}
	Renderer::Clear();

	return 0;
}
