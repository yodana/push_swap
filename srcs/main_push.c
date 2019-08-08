/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 02:11:42 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 02:12:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_all	res;
	int		mv;

	mv = 0;
	if (argc == 0)
		return (0);
	init(&res, argv, ft_size(argv));
	res.verif_exe = 1;
	while (res.a->size > 1)
		algo_go(&res, 0);
	while (check_win(res.a, res.b) == -1)
	{
		while (check_win(res.a, res.b) == -1 && check_tab(res.a) == 1)
			algo_go(&res, 1);
		while (check_tab(res.a) == -1)
			algo_go(&res, 2);
	}
	//ft_printf("mv == %d\n", res.c_mv);
	all_free(&res);
	return (0);
}
