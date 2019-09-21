/*

*/

#include "../header/system.h" //Prototype des fonctions
#include "../header/constant.h" //Constante

#include "../header/draw.h" //Constante

#include <stdlib.h> //EXIT_SUCCESS et EXIT_FAILURE
#include <SDL2/SDL.h> //Fonctions d'ouverture et fermeture de SDL et ces sous-systemes
#include <SDL2/SDL_ttf.h> //
#include <SDL2/SDL_image.h> //

//Initialisation des bibliotheque

/*

*/
void init_SDL()
{
    if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing SDL library...\n");
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Error SDL_Init() : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
    if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing SDL library : OK\n");
}

/*

*/
void init_SDL_TTF()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing SDL_ttf library...\n");
    if(TTF_Init() != 0)
	{
		fprintf(stderr, "Error TTF_Init() : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
    if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing SDL_ttf library : OK\n");
}

/*

*/
void init_SDL_IMAGE()
{
	fprintf(stderr, "WARNING !!!! : init_SDL_IMAGE not implemented\n");
}

/*

*/
void init_timer()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Timer...\n");
	if(SDL_InitSubSystem(SDL_INIT_TIMER) != 0)
	{
		fprintf(stderr, "Error SDL_InitSubSystem() : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Timer : OK\n");
}

/*

*/
void init_audio()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Audio...\n");
	if(SDL_InitSubSystem(SDL_INIT_AUDIO) != 0)
	{
		fprintf(stderr, "Error SDL_InitSubSystem() : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Audio : OK\n");
}

/*

*/
void init_events()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Events...\n");
	if(SDL_InitSubSystem(SDL_INIT_EVENTS) != 0)
	{
		fprintf(stderr, "Error SDL_InitSubSystem() : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Events : OK\n");
}

/*

*/
void init_controller()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Controller...\n");
	if(SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) != 0)
	{
		fprintf(stderr, "Error SDL_InitSubSystem() : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Initializing subsystem SDL Controller : OK\n");
}

/*

*/
void init_system()
{
	init_SDL();
	init_SDL_TTF();
	init_SDL_IMAGE();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "System initialized\n");
}

/*

*/
void init_subsystem()
{
	init_timer();
	init_audio();
	init_events();
	init_controller();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "Subsystem initialized\n");
}

/*

*/
int initialization()
{
	init_system();
	init_subsystem();

	create_window();

	create_renderer();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "All system initialized\n");

	return EXIT_SUCCESS;
}

//Fermeture des bibliotheque

/*

*/
void close_SDL()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing librairy SDL\n");
	SDL_Quit();
}

/*

*/
void close_SDL_TTF()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing librairy SDL_ttf\n");
	TTF_Quit();
}

/*

*/
void close_SDL_IMAGE()
{
	//if(LOG_INIT_SYSTEM) fprintf(stdout, "close_SDL_IMAGE not implemented\n");
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing librairy SDL_image\n");
	IMG_Quit();
}

/*

*/
void close_timer()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing subsystem SDL_timer\n");
	SDL_QuitSubSystem(SDL_INIT_TIMER);
}

/*

*/
void close_audio()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing subsystem SDL_audio\n");
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

/*

*/
void close_events()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing subsystem SDL_events\n");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

/*

*/
void close_controller()
{
	if(LOG_INIT_SYSTEM) fprintf(stdout, "Closing subsystem SDL_controller\n");
	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
}

/*

*/
void close_system()
{
	close_SDL_IMAGE();
	close_SDL_TTF();
	close_SDL();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "System closed\n");
}

/*

*/
void close_subsystem()
{
	close_timer();
	close_audio();
	close_events();
	close_controller();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "Subsystem closed\n");
}

/*

*/
int termination()
{
	destroy_renderer();
	destroy_window();

	close_subsystem();
	close_system();

	if(LOG_INIT_SYSTEM) fprintf(stdout, "All system closed\n");

	return EXIT_SUCCESS;
}