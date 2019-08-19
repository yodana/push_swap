/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:51:01 by yodana            #+#    #+#             */
/*   Updated: 2019/08/18 11:53:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../SDL2/include/SDL2/SDL.h"
# include "checker.h"

int				check_move(t_all *res, char *mv);
int				init(t_all *res, char **numbers, int size);
void			algo_go(t_all *res, int use);
int				move_pb(t_pile *a, t_pile *b);
void			ft_affichage(t_all *res);
int				move_ra(t_pile *a, t_pile *b);
int				move_rb(t_pile *a, t_pile *b);
int				move_pa(t_pile *a, t_pile *b);
int				move_sa(t_pile *a, t_pile *b);
int				move_sb(t_pile *a, t_pile *b);
int				move_rrb(t_pile *a, t_pile *b);
int				move_rra(t_pile *a, t_pile *b);
int				check_tab(int *target, int size);
int				check_win(t_pile *a, t_pile *b);
t_pile			*cpy_tab_pile(t_pile *a, t_pile *pa);
void			add_pivot(t_pile *p, int pivot);
void			algo_go2(t_all *res, int *mv);
void			algo_go3(t_all *res, int *mv);
void			all_free(t_all *res);
void			pile_free(t_pile *t);
void			algo_end_for_a(t_pile *tab_tmp, t_all *res, int c_ra, int pos);
void			algo_end_for_b(t_pile *tab_tmp, t_all *res, int c_rb, int pos, int c_ra);
void			algo_begin(int c, t_all *res, t_pile *tab_tmp, int pos);
void			algo_for_a(int c, t_all *res, t_pile *tab_tmp, int pos);
void			algo_for_b(int c, t_all *res, t_pile *tab_tmp, int pos);
void			ft_test(t_all	*res);
void			ft_error();
int				check_tab_b(t_pile *target);
void			algo_minus(t_pile *tmp, t_all *res);
int				ft_check_max(int *tab, int size);
typedef struct	s_algo
{
	int		type;
	void	(*algo)(int c, t_all *res, t_pile *tab_tmp, int pos);
}				t_algo;

#endif
