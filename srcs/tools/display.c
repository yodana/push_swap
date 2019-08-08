/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:13:21 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 00:13:41 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void  init_window(t_all	*res)
{
    SDL_Window *pWindow = NULL;
    SDL_Event event;
    SDL_Renderer* renderer;
    char *mv;
    int c;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        ft_printf("Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return ;
    }
      pWindow = SDL_CreateWindow("TEST SDL2",SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                                                1920,
                                                                1080,
                                               SDL_WINDOW_MAXIMIZED);
        renderer = SDL_CreateRenderer(pWindow, -1, 0);
        res->renderer = renderer;
        res->event = &event;
        res->window = 1;
        c = 0;
        if( pWindow )
        {
          while (1)
          {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
             { 
                SDL_DestroyWindow(pWindow); 
                exit(0);
             }
              if ((mv = ft_get_txt(0)) != NULL)
	            {
		            if (check_move(res, mv) == -1)
		            {
			            ft_strdel(&mv);
			            all_free(res); 
                  SDL_DestroyWindow(pWindow);
                  SDL_Quit();
			            write(2, "Error\n", 6);
			            exit(0) ;
		            }
                ft_strdel(&mv);
	            }
              else
                c++;
              if (c == 1)
              {
                  check_win(res->a, res->b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
                  while(1)
              {
                 SDL_PollEvent(&event);
                if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
                  { 
                SDL_DestroyWindow(pWindow); 
                exit(0);
                  }    
              }
              }
           }
           SDL_DestroyRenderer(renderer);
         SDL_DestroyWindow(pWindow);
        }
        else
            ft_printf("Erreur de création de la fenêtre: %s\n", SDL_GetError());
         SDL_Quit();
}

void   ft_affichage_window(int P_hor, int P_ver,t_all *res)
{
    int time = 0;
    int i = res->a->size - 1;
    int size = res->size;
    int int_ma = res->max_int;
    int c = 1;
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
        if (((P_hor / 2) / int_ma) > 0)
          rec.w = ((P_hor / 2) / int_ma) * ft_abs(res->a->numbers[i]);
        else
          rec.w = ft_abs(res->a->numbers[i]);
       if (rec.w > (1920 / 2))
          rec.w = 1920 / 2;
        rec.h = P_ver / size;
        if (rec.h == 0)
          rec.h = 1;
        rec.x = ((P_hor / 2) - rec.w) / 2;
        rec.y = P_ver - (rec.h * c);

        c++;
        SDL_RenderFillRect(res->renderer, &rec);
        i--;
      }
      i = res->b->size - 1;
       while (i >= 0)
      {
       if (i % 2 == 0)
          SDL_SetRenderDrawColor(res->renderer, 255,255, 255,255);
        else
          SDL_SetRenderDrawColor(res->renderer, 200,200, 200,200);
        SDL_RenderDrawLine(res->renderer, P_hor / 2 , 0, P_hor / 2, P_ver);
         if (((P_hor / 2) / int_ma) > 0)
          rec.w = ((P_hor / 2) / int_ma) * ft_abs(res->b->numbers[i]);
        else
          rec.w = ft_abs(res->a->numbers[i]);
        if (rec.w > (1920 / 2))
          rec.w = 1920 / 2;
        rec.h = (P_ver / size);
        if (rec.h == 0)
          rec.h = 1;
        rec.x = (((P_hor / 2) - rec.w) / 2) + (P_hor / 2);
        rec.y = P_ver - (rec.h * c);
        c++;
        SDL_RenderFillRect(res->renderer, &rec);
        i--;
      }
      SDL_RenderPresent(res->renderer);

      time = SDL_GetTicks() % 2147483647;
     while (time % 200)
      {
            time = SDL_GetTicks() % 2147483647;
            SDL_PollEvent(res->event);
            switch (res->event->type)
            {
              case SDL_QUIT:
              exit(0);
              break;
            case SDL_KEYDOWN:
            if (res->event->key.keysym.sym == SDLK_UP)
            { 
  
                ft_printf("OK WORK");
            }
            break;
            }
     }
}