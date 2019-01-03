
#include "const.h"

bool SDLInit(SDL_Window *&window, SDL_Renderer *&renderer) {
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Aircraft Wars",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		MAP_WIDTH,
		MAP_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		printf("Could not create renderer: %s\n", SDL_GetError());
		return false;
	}
	SDL_RenderPresent(renderer);
	return true;
}

void SDLDestroy(SDL_Window *window, SDL_Renderer *renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
