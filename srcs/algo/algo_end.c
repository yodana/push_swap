/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 07:05:02 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 07:05:08 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_end_for_a(t_pile *tab_tmp, t_all *res, int c_ra, int pos)
{
	if (tab_tmp->size >= 1)
		add_pivot(res->pb, tab_tmp->numbers[pos]);
	if (c_ra != res->a->size)
	{
		while (c_ra != 0)
		{
			move_rra(res->a, res->b);
			c_ra--;
		}
	}
	pile_free(tab_tmp);
	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	if (check_tab(tab_tmp) == 1 && res->pa->size > 0)
		res->pa->size = res->pa->size - 1;
	pile_free(tab_tmp);
}

void	algo_end_for_b(t_pile *tab_tmp, t_all *res, int c_rb, int pos)
{
	if (tab_tmp->size >= 1)
		add_pivot(res->pa, tab_tmp->numbers[pos]);
	if (res->pb->size > 0)
		res->pb->size = res->pb->size - 1;
	if (c_rb != res->b->size)
	{
		while (c_rb != 0)
		{
			move_rrb(res->a, res->b);
			c_rb--;
		}
	}
}
