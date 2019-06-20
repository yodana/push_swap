#include "checker.h"
#include <stdio.h>

static const t_moves    g_moves[] = {
        {"sa", move_sa},
        {"sb", move_sb},
        {"ss", move_ss},
        {"pa", move_pa},
        {"pb", move_pb},
        {"ra", move_ra},
        {"rb", move_rb},
        {"rr", move_rr},
        {"rra", move_rra},
        {"rrb", move_rrb},
        {NULL, NULL}
};

int     check_move(t_all *res, char *mv)
{
    int i;

    i = 0;
    while (g_moves[i].type)
    {
        if (ft_strcmp(mv, (const char*)g_moves[i].type) == 0)
        {
            g_moves[i].move(res->a, res->b);
            ft_affichage(res, res->a, res->b);
            return (1);
        }
        i++;
    }
    return (-1);
}