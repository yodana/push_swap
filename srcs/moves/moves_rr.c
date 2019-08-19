/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:33:19 by yodana            #+#    #+#             */
/*   Updated: 2019/07/21 23:34:20 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		move_rreverse(t_pile *target)
{
	int		i;
	int		save;

	i = target->size - 1;
	if (i < 0)
		return (1);
	save = target->numbers[target->size - 1];
	while (i > 0)
	{
		target->numbers[i] = target->numbers[i - 1];
		i--;
	}
	target->numbers[0] = save;
	return (1);
}

int		move_rrr(t_pile *a, t_pile *b)
{
		move_rreverse(b);
		move_rreverse(a);
		return (1);
}

int		move_rrb(t_pile *a, t_pile *b)
{
	(void)a;
	move_rreverse(b);
	return (1);
}

int		move_rra(t_pile *a, t_pile *b)
{
	(void)b;
	move_rreverse(a);
	return (1);
}
