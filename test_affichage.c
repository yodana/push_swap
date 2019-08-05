#include <SDL2/SDL.h>
#include "includes/push_swap.h"
#include <stdio.h>

void  ft_test(t_all	*res)
{
    /* Initialisation simple */
    SDL_Window *pWindow = NULL;
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Renderer* renderer1;
    SDL_Surface* pSurface = NULL;
    const int P_hor = res->size + 640;
    const int P_ver = res->size + 480;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return ;
    }

    {
        /* Création de la fenêtre */

        pWindow = SDL_CreateWindow("TEST SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  res->size + 640,
                                                                  res->size + 480,
                                                                  SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(pWindow, -1, 0);
        res->renderer = renderer;
        int c = 0;
        int time;
        if( pWindow )
        {
          int i = 0;
          while (1)
          {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT)
              break;
            if (c == 0)
            {
              while (res->a->size > 1)
	              algo_go(res, 0);
              c++;
            }
	          while (check_win(res->a, res->b) == -1)
	          {
		           while (check_win(res->a, res->b) == -1 && check_tab(res->a) == 1)
			            algo_go(res, 1);
		            while (check_tab(res->a) == -1)
			            algo_go(res, 2);
	          }
           // ft_time(renderer, P_hor, P_ver, tab,c);
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
}
