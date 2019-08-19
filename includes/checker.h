/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:43:20 by yodana            #+#    #+#             */
/*   Updated: 2019/08/18 11:50:37 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "../SDL2/include/SDL2/SDL.h"
# define INT_MAX "2147483647"

typedef struct	s_pile
{
	int *numbers;
	int size;
}				t_pile;

typedef struct	s_all
{
	t_pile			*a;
	t_pile			*b;
	t_pile			*pa;
	t_pile			*pb;
	SDL_Event		*event;
	SDL_Renderer	*renderer;
	int				max_int;
	double			delay;
	int				c_mv;
	int				size;
	int				verif_exe;
	int				window;

}				t_all;

typedef struct	s_moves
{
	char	*type;
	int		(*move)(t_pile *, t_pile *);
}				t_moves;

int				ft_size(char **argv);
int				move_sa(t_pile *a, t_pile *b);
int				move_sb(t_pile *a, t_pile *b);
int				move_ss(t_pile *a, t_pile *b);
int				move_pa(t_pile *a, t_pile *b);
int				move_pb(t_pile *a, t_pile *b);
int				move_ra(t_pile *a, t_pile *b);
int				move_rb(t_pile *a, t_pile *b);
int				move_rr(t_pile *a, t_pile *b);
int				move_rra(t_pile *a, t_pile *b);
int				move_rrb(t_pile *a, t_pile *b);
int				init(t_all *res, char **numbers, int size);
int				check_move(t_all *res, char *mv);
void			ft_affichage(t_all *res);
int				check_win(t_pile *a, t_pile *b);
int				check(char **argv);
int				check_double(t_pile *a);
void			all_free(t_all *res);
void			pile_free(t_pile *t);
void			ft_error();
void			init_window();
void			ft_affichage_window(int p_hor, int p_ver, t_all *res);
void			ft_display_a(int i, t_all *res, int p_hor, int p_ver);
void			ft_display_b(int i, t_all *res, int p_hor, int p_ver);

#endif
