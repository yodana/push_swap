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

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	t_all	res;
	int		mv;

	mv = 0;
	if (argc == 1)
		return (0);
	if (init(&res, argv, ft_size(argv)) == -1)
		return (0);
	res.verif_exe = 1;
	if (check(argv) == -1 || check_double(res.a) == -1)
	{
		ft_error();
		return (0);
	}
	while (res.a->size > 1 && check_win(res.a, res.b) == -1)
		algo_go(&res, 0);
	while (check_win(res.a, res.b) == -1)
	{
		while (check_win(res.a, res.b) == -1 && check_tab(res.a->numbers, res.a->size) == 1)
			algo_go(&res, 1);
		while (check_tab(res.a->numbers, res.a->size) == -1)
			algo_go(&res, 2);
	}
	all_free(&res);
	//ft_printf("mv == %d", res.c_mv);
	return (0);
}
