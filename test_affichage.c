#include <SDL2/SDL.h>

#include <stdio.h>

int main(int argc, char** argv)
{
    /* Initialisation simple */
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Surface* pSurface = NULL;
    const int P_hor = 640;
    const int P_ver = 480;
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        printf("Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;

        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  P_hor,
                                                                  P_ver,
                                                                  SDL_WINDOW_SHOWN);
    // SDL_RenderPresent(renderer);
     /*SDL_Rect rect = {100, 100, 100, 100};
    
    SDL_RenderFillRect(renderer, &rect); 
   // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
   // SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);
    SDL_RenderPresent(renderer);*/
        if( pWindow )
        {
            while (event.type != SDL_QUIT)
            {
                renderer = SDL_CreateRenderer(pWindow, -1, 0);
                SDL_RenderDrawLine(renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
            // SDL_WaitEvent(&event);/* Attendre trois secondes, que l'utilisateur voie la fenêtre */
             SDL_Rect rect = {100, 100, 100, 100};
             SDL_RenderFillRect(renderer, &rect);
             SDL_Rect rect1 = {P_hor / 2 + (P_hor / 5), 100, 100, 100};
            SDL_RenderFillRect(renderer, &rect1);
            SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, 255, 255));
                SDL_RenderPresent(renderer);
            }
            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}