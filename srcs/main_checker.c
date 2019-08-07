/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:18:26 by yodana            #+#    #+#             */
/*   Updated: 2019/07/21 23:23:11 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	//char	*mv;
	t_all	res;

	if (argc == 0)
		return (0);
	init(&res, argv, argc - 1);
	if (check(argv) == -1 || check_double(res.a) == -1)
	{
		ft_error();
		return (0);
	}
	ft_test(&res);
	/*while ((mv = ft_get_txt(0)) != NULL)
	{
		if (check_move(&res, mv) == -1)
		{
			ft_strdel(&mv);
			all_free(&res);
			ft_error();
			return (0);
		}
		ft_strdel(&mv);
	}*/
	//check_win(res.a, res.b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	all_free(&res);
	return (0);
}
