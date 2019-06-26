#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
#include "libft/libft.h"

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
    int size;

}         t_all;

typedef struct s_moves
{
    char *type;
    int  (*move)(t_pile *, t_pile *);
}               t_moves;

int     init(t_all *res, char **numbers, int size);
void    algo_go(t_pile *a, t_pile *b, int *mv);
int     move_pb(t_pile *a, t_pile *b);
void    ft_affichage(t_all *res, t_pile *a, t_pile *b);
int     move_ra(t_pile *a, t_pile *b);
int     move_rb(t_pile *a, t_pile *b);
int     move_pa(t_pile *a, t_pile *b);
int     move_sa(t_pile *a, t_pile *b);
int     move_sb(t_pile *a, t_pile *b);
int     check_win(t_pile *a, t_pile *b);
#endif