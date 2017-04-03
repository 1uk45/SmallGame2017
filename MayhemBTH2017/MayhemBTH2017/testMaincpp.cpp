#include <string>
#include "GUI.h"
#include "MasterShader.h"


int main(int argc, char *argv[])
{


	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

										   // Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL2 window",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	glewInit();

	GUI gui1("leo");

	Sprite s1;

	s1.Init(0.3f, 0.4f, 0.5f, 0.5f);

	gui1.AddSprite(s1);

	gui1.Update();

	gui1.Render();

	// The window is open: could enter program loop here (see SDL_PollEvent())

	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

					  // Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}