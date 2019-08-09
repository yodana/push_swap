/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:41:12 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 07:12:04 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_size(char **argv)
{
	int i;
	char **new;
	int 	b;
	int 	res;

	i = 1;
	res = 0;
	b = 0;
	if (argv[1][0] == '-' && argv[1][1] == 'v')
		i++;
	while(argv[i])
	{
		if (!(new = ft_strsplit(argv[i], ' ')))
			return (-1);
		while (new[b])
		{
			b++;
			res = res + 1;
		}
		b = 0;
		ft_strrdel(new);
		i++;
	}
	return (res);
}

t_pile	*cpy_tab_pile(t_pile *a, t_pile *pa)
{
	int		i;
	t_pile	*new;

	i = 0;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(new->numbers = (int*)malloc(sizeof(int) * a->size + 1)))
		return (NULL);
	if (pa->size == 0)
	{
		while (i < a->size)
		{
			new->numbers[i] = a->numbers[i];
			i++;
		}
	}
	else
	{
		i = -1;
		while (pa->numbers[pa->size - 1] != a->numbers[++i])
			new->numbers[i] = a->numbers[i];
	}
	new->size = i;
	return (new);
}

void	add_pivot(t_pile *p, int pivot)
{
	int i;

	i = p->size;
	p->numbers[i] = pivot;
	p->size = p->size + 1;
}
