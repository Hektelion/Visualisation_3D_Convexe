/*
    Fichier regroupant les prototypes des fonctions liées à l'initialisation du systeme et à ça fermeture

    Réalisé par BESSAI Sofiane
*/

#ifndef SYSTEM_H
#define SYSTEM_H

//Initialisation de l'interface

static void init_SDL();
static void init_SDL_TTF();
static void init_SDL_IMAGE();

static void init_timer();
static void init_audio();
static void init_events();
static void init_controller();

static void init_system();
static void init_subsystem();
int initialization();

//Fermeture de l'interface

static void close_SDL();
static void close_SDL_TTF();
static void close_SDL_IMAGE();

static void close_timer();
static void close_audio();
static void close_events();
static void close_controller();

static void close_system();
static void close_subsystem();
int termination();

#endif //SYSTEM_H