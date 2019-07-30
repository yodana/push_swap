#include <SDL2/SDL.h>

#include <stdio.h>

int main(int argc, char** argv)
{
    /* Initialisation simple */
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Renderer* renderer1;
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
                renderer = SDL_CreateRenderer(pWindow, -1, 0);
             SDL_RenderDrawLine(renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
             SDL_Rect rect = {100, 100, 100, 100};
             SDL_RenderFillRect(renderer, &rect);
             SDL_Rect rect1 = {P_hor / 2 , 100, 100, 100};
            SDL_RenderFillRect(renderer, &rect1);
           /* SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 255, 255, 255));*/
                SDL_RenderPresent(renderer);
                int c = 0;
        if( pWindow )
        {
            int i = 0;
           while (c == 0)
           {
            SDL_WaitEvent(&event);
             SDL_Rect rect1 = {P_hor / 2 + i++, 100, 100, 100};
            SDL_RenderFillRect(renderer, &rect1);
            SDL_RenderPresent(renderer);
            if (event.type == SDL_QUIT)
                c++;
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