/*
    Fichier regroupant les prototypes des fonctions liées à l'initialisation du systeme et à ça fermeture

    Réalisé par BESSAI Sofiane
*/

#include <SDL2/SDL.h>

#ifndef SYSTEM_H
#define SYSTEM_H

//Initialisation de l'interface

void init_SDL();
void init_SDL_TTF();
void init_SDL_IMAGE();

void init_timer();
void init_audio();
void init_events();
void init_controller();

void init_system();
void init_subsystem();

int initialization();

//Fermeture de l'interface

void close_SDL();
void close_SDL_TTF();
void close_SDL_IMAGE();

void close_timer();
void close_audio();
void close_events();
void close_controller();

void close_system();
void close_subsystem();

int termination();

#endif //SYSTEM_H