/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:13:21 by yodana            #+#    #+#             */
/*   Updated: 2019/08/09 14:59:23 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int   window_check(SDL_Event *event, SDL_Window *pWindow, char *mv, t_all *res)
{
      SDL_PollEvent(event);
			if (res->event->type == SDL_QUIT || res->event->key.keysym.sym == SDLK_ESCAPE)
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
				return (1);
      return (0);
}

void  window_go(SDL_Window *pWindow, SDL_Event *event, char *mv, t_all *res)
{
  int c;

  c = 0;
  if( pWindow )
	{
		while (1)
		{
      c = window_check(event, pWindow, mv, res);
			if (c == 1)
			{
				check_win(res->a, res->b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
				while(1)
				{
					SDL_PollEvent(event);
					if (res->event->type == SDL_QUIT || res->event->key.keysym.sym == SDLK_ESCAPE)
						exit(0); 
				}
			}
		}
		SDL_DestroyRenderer(res->renderer);
		SDL_DestroyWindow(pWindow);
	}
	SDL_Quit();
}

void  init_window(t_all	*res)
{
	SDL_Window *pWindow = NULL;
	SDL_Event event;
	SDL_Renderer* renderer;
	char *mv;

  mv = NULL;
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
  window_go(pWindow, &event, mv, res);
}

void   ft_display_b(int i, t_all *res, int p_hor, int p_ver)
{
	int c;

	SDL_Rect rec;
	c = 0;
	while (--i >= 0)
	{
		if (i % 2 == 0)
			SDL_SetRenderDrawColor(res->renderer, 255, 255, 255,255);
		else
			SDL_SetRenderDrawColor(res->renderer, 200, 200, 200, 200);
		SDL_RenderDrawLine(res->renderer, p_hor / 2 , 0, p_hor / 2, p_ver);
		if (((p_hor / 2) / res->max_int) > 0)
			rec.w = ((p_hor / 2) / res->max_int) * ft_abs(res->b->numbers[i]);
		else
			rec.w = ft_abs(res->b->numbers[i]);
		if (rec.w > (1920 / 2))
			rec.w = 1920 / 2;
		rec.h = p_ver / res->size;
		if (rec.h == 0)
			rec.h = 1;
		rec.x = ((p_hor / 2) - rec.w) / 2 + (p_hor / 2);
		rec.y = p_ver - (rec.h * c);
		c++;
		SDL_RenderFillRect(res->renderer, &rec);
	}
}

void   ft_display_a(int i, t_all *res, int p_hor, int p_ver)
{
	int c;
	SDL_Rect rec;

	c = 0;
	while (--i >= 0)
	{
		if (i % 2 == 0)
			SDL_SetRenderDrawColor(res->renderer, 255, 255, 255, 255);
		else
			SDL_SetRenderDrawColor(res->renderer, 200, 200, 200, 200);
		SDL_RenderDrawLine(res->renderer, p_hor / 2 , 0, p_hor / 2, p_ver);
		if (((p_hor / 2) / res->max_int) > 0)
			rec.w = ((p_hor / 2) / res->max_int) * ft_abs(res->a->numbers[i]);
		else
			rec.w = ft_abs(res->a->numbers[i]);
		if (rec.w > (1920 / 2))
			rec.w = 1920 / 2;
		rec.h = p_ver / res->size;
		if (rec.h == 0)
			rec.h = 1;
		rec.x = ((p_hor / 2) - rec.w) / 2;
		rec.y = p_ver - (rec.h * c);
		c++;
		SDL_RenderFillRect(res->renderer, &rec);
	}
}

void   ft_affichage_window(int p_hor, int p_ver, t_all *res)
{
	int time;

	time = 0;
	SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 0);
	SDL_RenderClear(res->renderer);
	ft_display_a(res->a->size + 1, res, p_hor, p_ver);
	ft_display_b(res->b->size + 1, res, p_hor, p_ver);
	SDL_RenderPresent(res->renderer);
	time = SDL_GetTicks() % 2147483647;
	while (time % 2)
	{
		time = SDL_GetTicks() % 2147483647;
		SDL_PollEvent(res->event);
		if (res->event->type == SDL_QUIT
          || res->event->key.keysym.sym == SDLK_ESCAPE)
		{
			exit(0);
		}
	}
}
