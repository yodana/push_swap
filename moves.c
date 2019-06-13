#include "checker.h"
#include <stdio.h>

int     move_sb(t_pile *a, t_pile *b)
{
    return (1);
}

static const t_moves    g_moves[] = {
        {"sb", move_sb},
        {NULL, NULL}
};

int     check_move(t_all *res, char *mv)
{
    int i;

    i = 0;
    while (g_moves[i].type)
    {
        if (mv == g_moves[i].type) 
            g_moves[i].move(res->a, res->b);        
        i++;
    }
    return (1);
}