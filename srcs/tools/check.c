/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 07:05:31 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 07:06:05 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		check_tab(t_pile *target)
{
	int i;

	i = 0;
	while (i + 1 < target->size)
	{
		if (target->numbers[i] > target->numbers[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		check_win(t_pile *a, t_pile *b)
{
	int i;

	i = 0;
	if (b->size > 0)
		return (-1);
	while (i + 1 < a->size)
	{
		if (a->numbers[i] > a->numbers[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		check_double(t_pile *a)
{
	int i;
	int j;

	j = 1;
	i = 0;
	while (i < a->size)
	{
		while (j < a->size)
		{
			if (a->numbers[i] == a->numbers[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int		real_check(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 10 || (ft_strlen(tab[i]) == 10
					&& (ft_strcmp(INT_MAX, tab[i]) < 0)))
			return (-1);
		while (tab[i][j])
		{
			if (tab[i][0] == '-' && tab[i][1] && j == 0)
				j++;
			if (ft_isdigit(tab[i][j]) != 1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		check(char **argv)
{
	int		i;
	char	**new;

	i = 1;
	if (argv[1][0] == '-' && argv[1][1] == 'v')
		i++;
	while (argv[i])
	{
		if (!(new = ft_strsplit(argv[i], ' ')))
			return (-1);
		if (real_check(new) == -1)
			return (-1);
		ft_strrdel(new);
		i++;
	}
	return (1);
}
