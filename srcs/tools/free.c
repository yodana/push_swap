/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 03:47:08 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 03:47:23 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	pile_free(t_pile *t)
{
	free(t->numbers);
	free(t);
}

void	all_free(t_all *res)
{
	pile_free(res->a);
	pile_free(res->b);
	pile_free(res->pa);
	pile_free(res->pb);
}
