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
	TTF_Font *police;
	police = NULL;
	SDL_Surface *texte;
	SDL_Texture *text;
	SDL_Rect textRec;
	SDL_Color couleurNoire = {255, 255, 255, 255};
		SDL_SetRenderDrawColor(res->renderer, 0, 0, 0, 0);
	SDL_RenderClear(res->renderer);
	ft_display_a(res->a->size + 1, res, p_hor, p_ver);
	ft_display_b(res->b->size + 1, res, p_hor, p_ver);
	if (res->commands->m == 1)
	{
	char *message;
	message = ft_strdup("Nombre de mouvements = ");
	message = ft_strjoin(message, ft_itoa(res->c_mv));
	time = 0;
	if ((police = TTF_OpenFont("/Users/yohanndana/Downloads/roboto/Roboto-Black.ttf", 65)) == NULL)
		ft_printf("Échec de l'initialisation de la SDL (%s)\n", TTF_GetError());
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
	//SDL_SetRenderDrawColor(res->renderer, 255, 255, 255, 255);
	//SDL_RenderClear(res->renderer);
    texte = TTF_RenderText_Solid(police, message, couleurNoire);
	ft_strdel(&message);
	text = SDL_CreateTextureFromSurface(res->renderer, texte);
	//int w = 100;
	//int h = 100;
	//SDL_QueryTexture(text, NULL, NULL, &w, &h);
	textRec.x = 1500;
	textRec.y = 0;
	textRec.h = 100;
	textRec.w = 400;
	SDL_RenderCopy(res->renderer, text, NULL, &textRec);
	}
	//SDL_RenderClear(res->renderer);
	SDL_RenderPresent(res->renderer);
	//SDL_RenderPresent(res->renderer);
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

