#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
#include "../libft/libft.h"

typedef struct s_pile
{
    int *numbers;
    int size;
    int p_pivot;
}       t_pile;

typedef struct s_all
{
    t_pile *a;
    t_pile *b;
    t_pile *pa;
    t_pile *pb;
    int c_mv;
    int size;

}         t_all;

typedef struct s_moves
{
    char *type;
    int  (*move)(t_pile *, t_pile *);
}               t_moves;

int		check_move(t_all *res, char *mv);
int     init(t_all *res, char **numbers, int size);
void    algo_go(t_all *res, int use);
int     move_pb(t_pile *a, t_pile *b);
void    ft_affichage(t_all *res);
int     move_ra(t_pile *a, t_pile *b);
int     move_rb(t_pile *a, t_pile *b);
int     move_pa(t_pile *a, t_pile *b);
int     move_sa(t_pile *a, t_pile *b);
int     move_sb(t_pile *a, t_pile *b);
int     move_rrb(t_pile *a, t_pile *b);
int     move_rra(t_pile *a, t_pile *b);
int     check_tab(t_pile *target);
int     check_win(t_pile *a, t_pile *b);
t_pile *cpy_tab_pile(t_pile *a, t_pile *pa);
void    add_pivot(t_pile *p, int pivot);
void    algo_go2(t_all *res, int *mv);
void        algo_go3(t_all *res, int *mv);
void     all_free(t_all *res);
void     pile_free(t_pile *t);
void	algo_end_for_a(t_pile *tab_tmp, t_all *res, int c_ra, int pos);
void	algo_end_for_b(t_pile *tab_tmp, t_all *res, int c_rb, int pos);
void	algo_begin(int c, t_all *res, t_pile *tab_tmp, int pos);
void	algo_for_a(int c, t_all *res, t_pile *tab_tmp, int pos);
void	algo_for_b(int c, t_all *res, t_pile *tab_tmp, int pos);
typedef struct s_algo
{
    int type;
    void  (*algo)(int c, t_all *res, t_pile *tab_tmp, int pos);
}              t_algo;

#endif