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
	if (tab_tmp->size >= 1 && (check_tab(res->a->numbers, res->a->size) == -1))
		add_pivot(res->pb, tab_tmp->numbers[pos]);
	if (c_ra != res->a->size)
	{
			if (c_ra < res->a->size / 2 || c_ra == 1)
			{
				while (c_ra != 0)
				{
					check_move(res, "rra");
					if (res->a->numbers[0] > res->a->numbers[1])
						check_move(res, "sa");
					c_ra--;
				}
			}
			else
			{
				while (res->a->size - c_ra != 0)
				{
					//ft_printf("lol\n");
					check_move(res, "ra");
					//if (res->a->numbers[0] > res->a->numbers[1])
					//	check_move(res, "sa");
					c_ra++;
				}
			}
			
	}
	pile_free(tab_tmp);
	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	if (check_tab(tab_tmp->numbers , tab_tmp->size) == 1 && res->pa->size > 0)
		res->pa->size = res->pa->size - 1;
	pile_free(tab_tmp);
}

void	algo_end_for_b(t_pile *tab_tmp, t_all *res, int c_rb, int pos, int c_ra)
{
	/*if (check_tab(res->a) == 1)
	{
		if (res->pa->size > 0)
			res->pa->size = res->pa->size - 1;
	}*/
	(void)c_ra;
	if (tab_tmp->size >= 1)
		add_pivot(res->pa, tab_tmp->numbers[pos]);
	if (res->pb->size > 0)
		res->pb->size = res->pb->size - 1;
	if (c_rb != res->b->size)
	{
		if (c_rb < (res->b->size / 2) || c_rb == 1)
		{
			while (c_rb != 0)
			{
				check_move(res, "rrb");
				if (res->b->numbers[0] < res->b->numbers[1])
					check_move(res, "sb");
				c_rb--;
			}
		}
		else
		{
			while (res->b->size - c_rb != 0)
			{
				check_move(res, "rb");
				//if (res->b->numbers[0] < res->b->numbers[1])
				//		check_move(res, "sb");
				c_rb++;
			}
		}
	}
	//if (res->a->numbers[0] > res->a->numbers[1])
	//	check_move(res, "sa");
}
