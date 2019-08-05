#include <SDL2/SDL.h>
#include "includes/push_swap.h"
#include <stdio.h>

/*void   ft_affichage_window(int P_hor, int P_ver,t_all *res)
{
    int time = 0;
    int i = res->a->size - 1;
    int size = res->size;
    int int_ma = 10;
    int c = 1;
    double f = 0.9;
    SDL_Rect rec;
    
     SDL_SetRenderDrawColor(res->renderer, 0,0, 0,0);
    SDL_RenderClear(res->renderer);
      while (i >= 0)
      {
        if (i % 2 == 0)
          SDL_SetRenderDrawColor(res->renderer, 255,255, 255,255);
        else
          SDL_SetRenderDrawColor(res->renderer, 200,200, 200,200);
        SDL_RenderDrawLine(res->renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
        rec.w = (640 / 2) / int_ma * res->a->numbers[i];
        rec.h = (480 / size);
        rec.x = (320 - rec.w) / 2;//(440 / 2);
        rec.y = 480 - (rec.h * c);
        c++;
        SDL_RenderFillRect(res->renderer, &rec);
        i--;
      }
      SDL_RenderPresent(res->renderer);
      while (time % 2000 != 0)
      {  
        time = SDL_GetTicks();
      }

}*/
void  ft_test(t_all	*res)
{
    /* Initialisation simple */
    SDL_Window *pWindow = NULL;
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Renderer* renderer1;
    SDL_Surface* pSurface = NULL;
    const int P_hor = 640;
    const int P_ver = 480;
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        printf("Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return ;
    }

    {
        /* Création de la fenêtre */

        pWindow = SDL_CreateWindow("TEST SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
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
