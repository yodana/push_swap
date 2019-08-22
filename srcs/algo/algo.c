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

int		check_tab_pivot_b(t_pile *a, int pivot)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->numbers[i] > pivot)
			return (-1);
		i++;
	}
	return (1);
}

int		check_tab_pivot(t_pile *a, int pivot)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->numbers[i] < pivot)
			return (-1);
		i++;
	}
	return (1);
}

void	algo_minus_b(t_pile *tmp, t_all *res)
{
	int c;

	c = 0;
	if (tmp->size <= 1)
		return ;
	if (tmp->size == 2)
	{
		if (tmp->numbers[0] < tmp->numbers[1])
			check_move(res, "sb");
		return ;
	}
	while (check_tab_b(tmp) == -1 || c != 0)
	{
		if (res->a->numbers[0] < res->a->numbers[1])
		{
			check_move(res, "sb");
			move_sa(tmp, tmp);
		}
		else if (c == 0)
		{
			check_move(res, "rb");
			c++;
			move_ra(tmp, tmp);
		}
		else if (c > 0)
		{
			c--;
			check_move(res, "rrb");
			move_rra(tmp, tmp);
		}
	}
}

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
	while (check_tab(res->a->numbers, res->a->size) == -1)
	{
		if (!(tmp = cpy_tab_pile(res->a, res->pa)))
			return ;
		if (tmp->numbers[0] > tmp->numbers[1])
		{
			check_move(res, "sa");
			//move_sa(tmp, tmp);
		}
		if (tmp->numbers[1] > tmp->numbers[2])
		{
			check_move(res, "rra");
			//c++;
			//move_ra(tmp, tmp);
		}
		pile_free(tmp);
		/*else if (res->size > 3 && c > 0)
		{
			c--;
			check_move(res, "rra");
			move_rra(tmp, tmp);
		}*/
	}
}

int		find_pos_pivot(t_pile *target, int pile)
{
	int i;
	//int	res = ft_check_max(target->numbers, target->size) / 2;

	i = 0;
	/*while (i + 1 < target->size)
	{
		if (target->numbers[i] == res)
			return (target->numbers[i]);
			i++;
	}*/
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
	/*if (res->b->size > 1 && res->b->numbers[0] < res->b->numbers[1])
		check_move(res, "sb");*/
	//if (check_tab(tab_tmp) == 1)
	//	return ;
	/*if (check_tab_b(tab_tmp) == 1)
	{
		if (res->pb->size > 0)
			res->pb->size = res->pb->size - 1;
		return ;
	}*/
	/*if (tab_tmp->size <= 3)
	{
		//res->c_mv = res->c_mv * 10;
		algo_minus_b(tab_tmp, res);
		if (res->pb->size > 0)
			res->pb->size = res->pb->size - 1;
		return ;
	}*/
	/*if (res->b->size > 1 && res->b->numbers[0] < res->b->numbers[1])
	{
		check_move(res, "sb");
		move_sa(tab_tmp, tab_tmp);
	}*/
	pos = find_pos_pivot(tab_tmp, 0);
	i = tab_tmp->size;
	int c_ra = 0;
	while (++c < i)
	{
		if (c > pos && check_tab(res->a->numbers, res->a->size - 1) == -1 && check_tab_pivot_b(res->b, tab_tmp->numbers[pos]) == 1)
		{
			//if (check_)
			//check_move(res, "rra");
			break ;
		}
		if (res->a->numbers[0] > res->a->numbers[1])
		{
				check_move(res, "sa");
				/*if (c > pos)
				{
					c_ra++;
					check_move(res, "ra");
				}*/
		}
		if (tab_tmp->numbers[c] >= tab_tmp->numbers[pos])
		{
			check_move(res, "pa");
			if (c == pos)
			{
				//ft_printf(RED "FDP" END_COLOR);
				check_move(res, "ra");
			}
			//	check_move(res, "ra");	
			//c > pos ? check_move(res, "sa") : 0;
		}
		else
			c_rb = c_rb + check_move(res, "rb");
	}
	//ft_printf("c_rb == %d && c_ra == %d", c_rb, c_ra);
	/*while (c_ra > 0)
	{//ft_printf(RED "FDP" END_COLOR);
		check_move(res, "rra");
		c_ra--;
	}*/
	//ft_printf("c_rb == %d && c_ra == %d", c_rb, c_ra);
	//if (res->b->numbers[0] < res->b->numbers[1])
	//	check_move(res, "sb");
	//ft_printf("pivot for b == %d\n", tab_tmp->numbers[pos]);
	algo_end_for_b(tab_tmp, res, c_rb, pos, c_ra);
	if (c > pos)
		check_move(res, "rra");
	pile_free(tab_tmp);
}

void	algo_for_a(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;
	int c_ra;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	/*if (res->a->size > 1 && res->a->numbers[0] > res->a->numbers[1])
	{
		check_move(res, "sa");
		move_sa(tab_tmp, tab_tmp);
	}*/
	pos = find_pos_pivot(tab_tmp, 0);
	//ft_printf("size of tab == %d && size of pa == %d\n",tab_tmp->size,res->pa->size);
	c_ra = 0;
	i = tab_tmp->size;
	while (++c < i && (check_tab(res->a->numbers, res->a->size) == -1))
	{
		if (i == 2)
		{
			if (check_tab(tab_tmp->numbers, tab_tmp->size) == 1)
				break ;
			else
			{
				check_move(res, "sa");
			}
			break ;
			
		}
		if (c > pos)
		{
			if (check_tab_pivot(res->a, tab_tmp->numbers[pos]) == 1)
				break ;
		}
		if (res->b->numbers[0] < res->b->numbers[1])
			check_move(res, "sb");
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			res->a->size > 1 ? check_move(res, "pb") : 0;
			if (res->a->size > 1 && res->b->size > 1 && c == pos)
			{
				check_move(res, "rb");
			}
			//c > pos ? check_move(res, "sb") : 0;
		}
		else 
			c_ra = c_ra + check_move(res, "ra");
	}
	if (res->b->size > 1 && c > pos)
		check_move(res, "rrb");
	//if (res->a->numbers[0] > res->a->numbers[1])
		//check_move(res, "sa");
	algo_end_for_a(tab_tmp, res, c_ra, pos);
}

void	algo_begin(int c, t_all *res, t_pile *tab_tmp, int pos)
{
	int i;

	if (!(tab_tmp = cpy_tab_pile(res->a, res->pa)))
		return ;
	if (res->size <= 3)
	{
		algo_minus(tab_tmp, res);
		return ;
	}
	pos = find_pos_pivot(res->a, 0);
	i = res->a->size;
	while (++c < i)
	{
		if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
		{
			if (c < pos && res->b->size > 0)
			{
				if (res->b->numbers[0] < res->b->numbers[1])
					check_move(res, "sb");
			}
			check_move(res, "pb");
			if (c > pos)
				check_move(res, "sb");
		}
		else if (res->a->size > 1) //&& check_tab(res->a->numbers, res->a->size) == -1)
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
	//ft_printf( RED "new pivot\n" END_COLOR);
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
