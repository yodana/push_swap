/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:29:15 by yodana            #+#    #+#             */
/*   Updated: 2019/07/21 23:29:16 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		ft_check_max(int *tab, int size)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (res < ft_abs(tab[i]))
			res = ft_abs(tab[i]);
		i++;
	}
	return (res);
}

t_pile	*init_pile_b(int size)
{
	t_pile *b;

	if (!(b = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(b->numbers = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	b->size = 0;
	return (b);
}

t_pile	*init_pile_a(char **numbers, int size)
{
	int		i;
	int		j;
	t_pile	*a;
	char **new;
	int 	b;

	i = 1;
	j = 0;
	b = 0;
	if (!(a = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(a->numbers = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	if (numbers[1][0] == '-' && numbers[1][1] == 'v')
		i++;
	while (numbers[i])
	{
		if (!(new = ft_strsplit(numbers[i], ' ')))
			return (NULL);
		while (new[b])
		{
			a->numbers[j] = ft_atoi(new[b]);
			b++;
			j++;
		}
		b = 0;
		i++;
	}
	a->size = size;
	return (a);
}

int		init(t_all *res, char **numbers, int size)
{
	if (size < 0)
		return (-1);
	if (!(res->a = init_pile_a(numbers, size)))
		return (-1);
	if (!(res->b = init_pile_b(size)))
		return (-1);
	if (!(res->pa = init_pile_b(size)))
		return (-1);
	if (!(res->pb = init_pile_b(size)))
		return (-1);
	res->renderer = NULL;
	res->size = size;
	res->event = NULL;
	res->delay = 200;
	res->window = 0;
	res->max_int = ft_check_max(res->a->numbers, res->a->size);
	return (1);
}
