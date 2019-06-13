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
    int  (*move)(t_pile *, t_pile *b);
}               t_moves;

int     init(t_all *res, char **numbers, int size);
int     check_move(t_all *res, char *mv);
#endif