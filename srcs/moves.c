/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:29:54 by yodana            #+#    #+#             */
/*   Updated: 2019/07/21 23:30:12 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static const t_moves	g_moves[] = {
	{"sa", move_sa},
	{"sb", move_sb},
	{"ss", move_ss},
	{"pa", move_pa},
	{"pb", move_pb},
	{"ra", move_ra},
	{"rb", move_rb},
	{"rr", move_rr},
	{"rra", move_rra},
	{"rrb", move_rrb},
	{NULL, NULL}
};

int		check_move(t_all *res, char *mv)
{
	int i;

	i = 0;
	while (g_moves[i].type)
	{
		if (ft_strcmp(mv, (const char*)g_moves[i].type) == 0)
		{
			g_moves[i].move(res->a, res->b);
			ft_affichage(res);
			return (1);
		}
		i++;
	}
	return (-1);
}