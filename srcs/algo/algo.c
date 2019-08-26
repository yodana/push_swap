/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 03:55:06 by yodana            #+#    #+#             */
/*   Updated: 2019/08/26 16:12:46 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static const t_algo	g_algo[] = {
	{0, algo_begin},
	{1, algo_for_b},
	{2, algo_for_a},
	{-1, NULL}
};

void	algo_minus(t_pile *tmp, t_all *res)
{
	int c;

	c = 0;
	if (tmp->size <= 1)
		return ;
	if (tmp->size == 2)
	{
		if (tmp->numbers[0] > tmp->numbers[1])
			check_move(res, "sa");
		return ;
	}
	pile_free(tmp);
	while (check_tab(res->a->numbers, res->a->size) == -1)
	{
		if (!(tmp = cpy_tab_pile(res->a, res->pa)))
			return ;
		if (tmp->numbers[0] > tmp->numbers[1])
			check_move(res, "sa");
		if (tmp->numbers[1] > tmp->numbers[2])
			check_move(res, "rra");
		pile_free(tmp);
	}
}

void	algo_for_b(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int c_rb;

	c_rb = 0;
	if (!(tab_tmp = cpy_tab_pile(res->b, res->pb)))
		return ;
	pos = find_pos_pivot(tab_tmp, 0);
	while (++c < tab_tmp->size)
	{
		if (c > pos && check_tab(res->a->numbers, res->a->size - 1) == -1
				&& check_tab_pivot_b(res->b, tab_tmp->numbers[pos]) == 1)
			break ;
		res->a->numbers[0] > res->a->numbers[1] ? check_move(res, "sa") : 0;
		if (tab_tmp->numbers[c] >= tab_tmp->numbers[pos])
		{
			check_move(res, "pa");
			if (res->a->size > 1 && c == pos)
				check_move(res, "ra");
		}
		else
			c_rb = c_rb + check_move(res, "rb");
	}
	algo_end_for_b(tab_tmp, res, c_rb, pos);
	if (res->a->size > 1 && c > pos)
		check_move(res, "rra");
	pile_free(tab_tmp);
}

void	algo_for_a(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int c_ra;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	pos = find_pos_pivot(tab_tmp, 0);
	c_ra = 0;
	while (++c < tab_tmp->size
			&& (check_tab(res->a->numbers, res->a->size) == -1))
	{
		if (c > pos && check_tab_pivot(res->a, tab_tmp->numbers[pos]) == 1)
			break ;
		if (res->b->numbers[0] < res->b->numbers[1])
			check_move(res, "sb");
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			res->a->size > 1 ? check_move(res, "pb") : 0;
			if (res->a->size > 1 && res->b->size > 1 && c == pos)
				check_move(res, "rb");
		}
		else
			c_ra = c_ra + check_move(res, "ra");
	}
	if (res->b->size > 1 && c > pos)
		check_move(res, "rrb");
	algo_end_for_a(tab_tmp, res, c_ra, pos);
}

void	algo_begin(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	if (res->size <= 3)
		algo_minus(tab_tmp, res);
	pos = find_pos_pivot(res->a, 0);
	i = res->a->size;
	while (res->size > 3 && ++c < i)
	{
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			if (c < pos && res->b->size > 0
					&& res->b->numbers[0] < res->b->numbers[1])
				check_move(res, "sb");
			check_move(res, "pb");
			if (c > pos)
				check_move(res, "sb");
		}
		else if (res->a->size > 1)
			check_move(res, "ra");
	}
	add_pivot(res->pb, tab_tmp->numbers[pos]);
	if (res->size > 3)
		pile_free(tab_tmp);
}

void	algo_go(t_all *res, int use)
{
	t_pile	*tab_tmp;
	int		i;

	i = 0;
	tab_tmp = NULL;
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
