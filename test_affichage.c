#include <SDL2/SDL.h>

#include <stdio.h>
void  ft_exit(SDL_Event *event)
{
  while (SDL_PollEvent(event))
  {
    if (event->type == SDL_KEYDOWN)
    {
      (event->key.keysym.sym == SDLK_ESCAPE) ? exit(0) : 0;
    }
  }
}

void    ft_time(SDL_Renderer *renderer, int P_hor, int P_ver)
{
    int time = 0;
 time = SDL_GetTicks();
            if (time % 2000 == 0)
            {
              SDL_SetRenderDrawColor(renderer, 0,0, 0,0);
              SDL_RenderClear(renderer);
               SDL_SetRenderDrawColor(renderer, 255,255, 255,255);
              SDL_RenderDrawLine(renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
              SDL_RenderPresent(renderer);
            }
            if (time % 4000 == 0)
            {
              SDL_SetRenderDrawColor(renderer, 0,0, 0,0);
              SDL_RenderClear(renderer);
               SDL_SetRenderDrawColor(renderer, 255,0, 0,255);
              SDL_RenderDrawLine(renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
              SDL_RenderPresent(renderer);
            }
}
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
        int tab[2] = {1, 2};
         SDL_Rect rec = {100,100,100,100};
        SDL_SetRenderDrawColor(renderer, 255,255, 255,255);
         SDL_RenderFillRect(renderer, &rec);
        // SDL_RenderPresent(renderer);
        rec.x = 200;
        rec.y = 200;
        rec.h = 200;
        rec.w = 200;
         SDL_RenderFillRect(renderer, &rec);
          SDL_RenderDrawLine(renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
           SDL_RenderPresent(renderer);
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
             // ft_time(renderer, P_hor, P_ver);
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
