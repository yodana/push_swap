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
	char	*mv;
	int		c;

	c = 0;
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

void	checker_go(t_all *res)
{
	if (res->commands->v == 1)
		init_window(res);
	else
		read_mv(res);
	check_win(res->a, res->b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	if (res->commands->m == 1)
		ft_printf("Mouvements == %d", res->c_mv);
}

int		main(int argc, char **argv)
{
	t_all	res;
	int		i;

	if (argc == 1)
		return (0);
	i = ft_parsing_argv(argv, &res);
	res.verif_exe = 0;
	if (init(&res, &argv[i], ft_size(argv)) == -1)
		return (0);
	if (check(&argv[i]) == -1 || check_double(res.a) == -1)
	{
		ft_error();
		return (0);
	}
	if (check_win(res.a, res.b) == 1)
	{
		if (res.commands->v == 1)
			init_window(&res);
		else
			ft_printf("OK\n");
		return (0);
	}
	checker_go(&res);
	all_free(&res);
	return (0);
}
