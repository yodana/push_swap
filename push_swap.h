#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
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

int     init(t_all *res, char **numbers, int size);
#endif