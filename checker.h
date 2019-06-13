#ifndef CHECKER_H
# define CHECKER_H
#include "libft/libft.h"

typedef struct s_pile
{
    int *numbers;
    int size;
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

int     move_sa(t_pile *a, t_pile *b);
int     move_sb(t_pile *a, t_pile *b);
int     move_ss(t_pile *a, t_pile *b);
int     init(t_all *res, char **numbers, int size);
int     check_move(t_all *res, char *mv);
void    ft_affichage(t_all *res, t_pile *a, t_pile *b);
#endif