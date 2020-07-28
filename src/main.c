#include "include/main.h"

SDL_Surface *ecran = NULL;


int main(int argc, char **argv)
{
    prog_init(argc , argv);

    SDL_Surface *lignes[256] = {NULL};
    SDL_Rect position;
    int i = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 256, 32, SDL_HWSURFACE);

    for (i = 0 ; i <= 255 ; i++)
        lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 1, 32, 0, 0, 0, 0);

    SDL_WM_SetCaption(APP_NAME, NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    for (i = 0 ; i <= 255 ; i++)
    {
        position.x = 0; // Les lignes sont à gauche (abscisse de 0)
        position.y = i; // La position verticale dépend du numéro de la ligne
        SDL_FillRect(lignes[i], NULL, SDL_MapRGB(ecran->format, i, i, i));
        SDL_BlitSurface(lignes[i], NULL, ecran, &position);
    }

    SDL_Flip(ecran);
    pause();

    for (i = 0 ; i <= 255 ; i++) // N'oubliez pas de libérer les 256 surfaces
        SDL_FreeSurface(lignes[i]);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    // static int r= 10;
    // static int g= 10;
    // static int b= 10;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }

        // printf("%d" , r);


    }
}

void prog_init(int argc, char **argv){
    
    (void)argc;
    (void)argv;

}
