
#include <stdio.h>
#include <SDL2/SDL.h>

#include "../header/draw.h"
#include "../header/constant.h"

static SDL_Window *main_window = NULL;
static SDL_Renderer *main_renderer = NULL;

void create_window()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Creating window...\n");

	main_window = SDL_CreateWindow( APP_NAME,
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								640,
								480,
								SDL_WINDOW_RESIZABLE);

	if(main_window == NULL)
	{
		fprintf(stderr, "Error SDL_CreateWindow : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(LOG_INIT_SYSTEM) fprintf(stdout, "Window created\n");
}

void create_renderer()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Creating renderer...\n");

	if(main_window == NULL)
	{
		fprintf(stderr, "Error window not created\n");
		exit(EXIT_FAILURE);
	}

	main_renderer = SDL_CreateRenderer(main_window,
	-1,
	SDL_RENDERER_ACCELERATED);

	if(main_renderer == NULL)
	{
		fprintf(stderr, "Error SDL_CreateRenderer : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(LOG_INIT_SYSTEM) fprintf(stdout, "Renderer created\n");
}

void destroy_window()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Destructing window\n");

	if(main_window != NULL)
	{
		SDL_DestroyWindow(main_window);
	}
	else
	{
		SDL_DestroyWindow(main_window);
		fprintf(stderr, "Error SDL_DestroyWindow : %s\n", SDL_GetError());
	}
}

void destroy_renderer()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Destructing renderer\n");

	if(main_renderer != NULL)
	{
		SDL_DestroyRenderer(main_renderer);
	}
	else
	{
		SDL_DestroyRenderer(main_renderer);
		fprintf(stderr, "Error SDL_DestroyRenderer : %s\n", SDL_GetError());
	}
}

