/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:34:10 by yodana            #+#    #+#             */
/*   Updated: 2019/08/18 11:34:22 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_affichage_window(int p_hor, int p_ver, t_all *res)
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

