#include "checker.h"
#include <stdio.h>

int     move_sa(t_pile *a, t_pile *b)
{
    int i;

    i = 0;
    if (b->numbers[0] && b->numbers[1])
    {
        while (i <= b->size)
        {
            b->numbers[i + 2] = b->numbers[i];
            i++;
        }
    }
    while (i + 2 <= b->size)
    {
        a->numbers[i] = a->numbers[i + 2];
        i++;
    }
    return (1);
}

static const t_moves    g_moves[] = {
        {"sa", move_sa},
        {NULL, NULL}
};

int     check_move(t_all *res, char *mv)
{
    int i;

    i = 0; 
    while (g_moves[i].type)
    {
        if (ft_strcmp(mv, (const char*)g_moves[i].move)) 
            g_moves[i].move(res->a, res->b); 
        i++;
    }
    return (1);
}