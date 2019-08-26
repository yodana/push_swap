/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:34:10 by yodana            #+#    #+#             */
/*   Updated: 2019/08/26 19:07:35 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	chose_color(int i, t_all *res)
{
	if (i % 2 == 0)
		SDL_SetRenderDrawColor(res->renderer, res->commands->color_b,
			res->commands->color_g, res->commands->color_r, 255);
	else
		SDL_SetRenderDrawColor(res->renderer, res->commands->color_b - 55,
			res->commands->color_g - 55, res->commands->color_r - 55, 255);
}

void	ft_display_text(t_all *res, TTF_Font *police)
{
	SDL_Surface		*texte;
	SDL_Texture		*text;
	SDL_Rect		textrec;
	SDL_Color		blanche;
	char			*message;

	blanche.a = 255;
	blanche.b = 255;
	blanche.g = 255;
	blanche.r = 255;
	message = ft_strdup("Nombre de mouvements = ");
	message = ft_strjoin(message, ft_itoa(res->c_mv));
	texte = TTF_RenderText_Solid(police, message, blanche);
	ft_strdel(&message);
	text = SDL_CreateTextureFromSurface(res->renderer, texte);
	textrec.x = 1300;
	textrec.y = 0;
	textrec.h = 100;
	textrec.w = 500;
	SDL_RenderCopy(res->renderer, text, NULL, &textrec);
}

void	ft_affichage_window(int p_hor, int p_ver, t_all *res)
{
	int			time;
	TTF_Font	*police;

	time = 0;
	police = NULL;
	SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 0);
	SDL_RenderClear(res->renderer);
	ft_display_a(res->a->size + 1, res, p_hor, p_ver);
	ft_display_b(res->b->size + 1, res, p_hor, p_ver);
	if (res->commands->m == 1 &&
			(police = TTF_OpenFont("/Users/yodana/Downloads/angelina.TTF", 65))
				!= NULL)
		ft_display_text(res, police);
	TTF_CloseFont(police);
	SDL_RenderPresent(res->renderer);
}
