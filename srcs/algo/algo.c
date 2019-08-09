/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 03:55:06 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 07:04:08 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static const t_algo	g_algo[] = {
	{0, algo_begin},
	{1, algo_for_b},
	{2, algo_for_a},
	{-1, NULL}
};

int		find_pos_pivot(t_pile *target, int pile)
{
	int i;

	pile = 1;
	i = target->size / 2;
	return (i);
}

void	algo_for_b(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;
	int c_rb;

	c_rb = 0;
	if (!(tab_tmp = cpy_tab_pile(res->b, res->pb)))
		return ;
	pos = find_pos_pivot(tab_tmp, 0);
	i = tab_tmp->size;
	while (++c < i)
	{
		if (c < pos)
		{
			if (res->a->numbers[0] > res->a->numbers[1])
				check_move(res, "sa");
		}
		if (tab_tmp->numbers[c] >= tab_tmp->numbers[pos])
		{
			check_move(res, "pa");
			c > pos ? check_move(res, "sa") : 0;
		}
		else
			c_rb = c_rb + check_move(res, "rb");
	}
	algo_end_for_b(tab_tmp, res, c_rb, pos);
	pile_free(tab_tmp);
}

void	algo_for_a(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;
	int c_ra;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	pos = find_pos_pivot(tab_tmp, 0);
	c_ra = 0;
	i = tab_tmp->size;
	while (++c < i)
	{
		if (c < pos)
		{
			if (res->b->numbers[0] < res->b->numbers[1])
				check_move(res, "sb");
		}
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			res->a->size > 1 ? check_move(res, "pb") : 0;
			c > pos ? check_move(res, "sb") : 0;
		}
		else
			c_ra = c_ra + check_move(res, "ra");
	}
	algo_end_for_a(tab_tmp, res, c_ra, pos);
}

void	algo_begin(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	pos = find_pos_pivot(res->a, 0);
	i = res->a->size;
	while (++c < i)
	{
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			if (c < pos)
			{
				if (res->b->numbers[0] > res->b->numbers[1])
					check_move(res, "sb");
			}
			check_move(res, "pb");
			if (c > pos)
				check_move(res, "sb");
		}
		else if (res->a->size > 1)
			check_move(res, "ra");
	}
	add_pivot(res->pb, tab_tmp->numbers[pos]);
	pile_free(tab_tmp);
}

void	algo_go(t_all *res, int use)
{
	t_pile	*tab_tmp;
	int		i;

	i = 0;
	tab_tmp = NULL;
	(void)g_algo;
	while (g_algo[i].algo)
	{
		if (g_algo[i].type == use)
		{
			g_algo[i].algo(-1, res, tab_tmp, 0);
			return ;
		}
		i++;
	}
}
