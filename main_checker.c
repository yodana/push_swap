#include "checker.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
    char *mv;
    t_all res;

    if (argc == 0)
        return (0);
    init(&res, argv, argc - 1);
    while ((mv = ft_get_txt(0)) != NULL)
         check_move(&res, mv);
    check_win(res.a, res.b) == 1 ? ft_putstr("OK\n") : ft_putstr("KO\n");
    return (0);
}