/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:13:21 by yodana            #+#    #+#             */
/*   Updated: 2019/08/18 11:15:37 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		window_check(SDL_Event *event, SDL_Window *pwindow, char *mv, t_all *r)
{
	SDL_PollEvent(event);
	if (r->event->type == SDL_QUIT
		|| r->event->key.keysym.sym == SDLK_ESCAPE)
	{
		SDL_DestroyWindow(pwindow);
		exit(0);
	}
	if ((mv = ft_get_txt(0)) != NULL)
	{
		if (check_move(r, mv) == -1)
		{
			ft_strdel(&mv);
			all_free(r);
			SDL_DestroyWindow(pwindow);
			SDL_Quit();
			write(2, "Error\n", 6);
			exit(0);
		}
		ft_strdel(&mv);
	}
	else
		return (1);
	return (0);
}

void	window_go(SDL_Window *pwindow, SDL_Event *event, char *mv, t_all *res)
{
	int c;
	TTF_Font *police;
	police = NULL;
	SDL_Surface *texte;
    SDL_Color couleurNoire = {0, 0, 0, 0};
	c = 0;
	if (pwindow)
	{
		while (1)
		{
			ft_affichage_window(1920, 1080, res);
			c = window_check(event, pwindow, mv, res);
				/* Chargement de la police */
    if ((police = TTF_OpenFont("/Users/yodana/Downloads/angelina.TTF", 65)) == NULL)
		ft_printf("Échec de l'initialisation de la SDL (%s)\n", TTF_GetError());
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);
			if (c == 1)
			{
				check_win(res->a, res->b) == 1 ?
					ft_printf("OK\n") : ft_printf("KO\n");
				if (res->commands->m == 1)
					ft_printf("Mouvements == %d", res->c_mv);
				while (1)
				{
					SDL_PollEvent(event);
					if (res->event->type == SDL_QUIT
						|| res->event->key.keysym.sym == SDLK_ESCAPE)
						exit(0);
				}
			}
		}
		SDL_DestroyRenderer(res->renderer);
		SDL_DestroyWindow(pwindow);
	}
	SDL_Quit();
}

void	init_window(t_all *res)
{
	SDL_Window		*pwindow;
	SDL_Event		event;
	SDL_Renderer	*renderer;
	char			*mv;

	mv = NULL;
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		ft_printf("Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return ;
	}
	pwindow = SDL_CreateWindow("TEST SDL2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1920,
			1080,
			SDL_WINDOW_MAXIMIZED);
	renderer = SDL_CreateRenderer(pwindow, -1, 0);
	res->renderer = renderer;
	res->event = &event;
	//res->window = 1;
	window_go(pwindow, &event, mv, res);
}

void	ft_display_b(int i, t_all *res, int p_hor, int p_ver)
{
	int			c;
	SDL_Rect	rec;

	c = 0;
	while (--i >= 0)
	{
		if (i % 2 == 0)
			SDL_SetRenderDrawColor(res->renderer, res->commands->color_b, res->commands->color_g, res->commands->color_r, 255);
		else
			SDL_SetRenderDrawColor(res->renderer, res->commands->color_b - 55, res->commands->color_g - 55, res->commands->color_r - 55, 255);
		SDL_RenderDrawLine(res->renderer, p_hor / 2, 0, p_hor / 2, p_ver);
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

void	ft_display_a(int i, t_all *res, int p_hor, int p_ver)
{
	int			c;
	SDL_Rect	rec;

	c = 0;
	while (--i >= 0)
	{
		if (i % 2 == 0)
			SDL_SetRenderDrawColor(res->renderer, res->commands->color_b, res->commands->color_g, res->commands->color_r, 255);
		else
			SDL_SetRenderDrawColor(res->renderer, res->commands->color_b - 55, res->commands->color_g - 55, res->commands->color_r - 55, 255);
		SDL_RenderDrawLine(res->renderer, p_hor / 2, 0, p_hor / 2, p_ver);
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
