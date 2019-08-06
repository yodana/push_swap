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

void   ft_affichage_window(int P_hor, int P_ver,t_all *res)
{
    int time = 0;
    int i = res->a->size - 1;
    int size = res->size;
    int int_ma = 200;
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
        rec.w = ((P_hor / 2) / int_ma) * res->a->numbers[i];
        rec.h = P_ver / size;
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
        rec.w = (P_hor / 2) / int_ma * res->b->numbers[i];
        rec.h = (P_ver / size);
        rec.x = (((P_hor / 2) - rec.w) / 2) + (P_hor / 2);
        rec.y = P_ver - (rec.h * c);
        c++;
        SDL_RenderFillRect(res->renderer, &rec);
        i--;
      }
      SDL_RenderPresent(res->renderer);
      time = SDL_GetTicks() % 2147483647;
      while (time % (int)res->delay)
      {
            time = SDL_GetTicks() % 2147483647;
            printf("time == %d\n", (int)res->delay);
            SDL_PollEvent(res->event);
            if (res->event->type == SDL_QUIT || res->event->key.keysym.sym == SDLK_ESCAPE)
            { 
               //SDL_DestroyWindow(pWindow); 
                exit(0);
            }
           /* if (res->event->key.keysym.sym == SDLK_UP)
              res->delay = res->delay + 0.01;
            if (res->event->key.keysym.sym == SDLK_DOWN)
            res->delay = res->delay - 0.01;*/
     }
}