/*

*/

#include <stdio.h>
#include <SDL2/SDL.h>

#include "../header/system.h" //Prototype des fonctions

int main()
{

    //INITIALISATION DU PROGRAMME
    initialization();

    //PROGRAM
    SDL_Delay(3000);

    //TERMINAISON DU PROGRAMME
    termination();

    return 0;
}