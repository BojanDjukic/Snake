#include "controller.h"

static SDL_Event event;

int handleUserCommands()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) return -2;
		if (event.type == SDL_KEYDOWN)
		{
			SDLKey keyPressed = event.key.keysym.sym;
			if ( keyPressed == SDLK_ESCAPE ) return -2;
			if ( keyPressed == SDLK_RIGHT ) return 0;
			if ( keyPressed == SDLK_DOWN )  return 1;
			if ( keyPressed == SDLK_LEFT ) return 2;
			if ( keyPressed == SDLK_UP ) return 3;
			
		}
	}
	return -3;
}





