#include "include/main.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;


int main(int argc, char **argv)
{
    prog_init(argc , argv);

    SDL_Surface *lignes[256] = {NULL};
    SDL_Rect position;
    int i = 0;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow( APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        exit(EXIT_FAILURE);
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Wait two seconds
    SDL_Delay( 2000 );


    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;

    return EXIT_SUCCESS;
}


void prog_init(int argc, char **argv){
    
    (void)argc;
    (void)argv;

}
