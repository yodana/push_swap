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

void	read_mv(t_all *res)
{
	char *mv;

	while ((mv = ft_get_txt(0)) != NULL)
	{
		if (check_move(res, mv) == -1)
		{
			ft_strdel(&mv);
			all_free(res);
			ft_error();
			exit(0);
		}
		ft_strdel(&mv);
	}
}

int		main(int argc, char **argv)
{
	t_all	res;

	if (argc == 1)
		return (0);
	if (init(&res, argv, ft_size(argv)) == -1)
		return (0);
	res.verif_exe = 0;
	if (check(argv) == -1 || check_double(res.a) == -1)
	{
		ft_error();
		return (0);
	}
	if (check_win(res.a, res.b) == 1)
	{
		ft_printf("OK\n");
		return (0);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'v')
		init_window(&res);
	else
		read_mv(&res);
	check_win(res.a, res.b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	all_free(&res);
	return (0);
}
