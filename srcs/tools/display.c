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
    //int time = 0;
    int i = res->a->size - 1;
    int size = res->size;
    int int_ma = 100;
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
        rec.w = (640 / 2) / int_ma * res->a->numbers[i];
        rec.h = (480 / size);
        rec.x = (320 - rec.w) / 2;//(440 / 2);
        rec.y = 480 - (rec.h * c);
        c++;
        SDL_RenderFillRect(res->renderer, &rec);
        i--;
      }
      SDL_RenderPresent(res->renderer);
	  double f = 1;
      sleep(f);

}
/*void	ft_affichage(t_all *res)
{
	int i;

	i = 0;
	ft_printf(" A\n");
	while (i < res->size)
	{
		if (i < res->a->size)
			ft_printf("|%d| ", res->a->numbers[i]);
		else
			ft_printf("|| ");
		i++;
	}
	i = 0;
	ft_printf("\n B\n");
	while (i < res->size)
	{
		if (i < res->b->size)
			ft_printf("|%d| ", res->b->numbers[i]);
		else
			ft_printf("|| ");
		i++;
	}
	ft_printf("\n");
}*/
