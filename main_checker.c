#include "checker.h"
#include <stdio.h>

void    ft_error()
{
    write(2, "Error\n", 6);
}

int     main(int argc, char **argv)
{
    char *mv;
    t_all res;

    if (argc == 0)
        return (0);
    init(&res, argv, argc - 1);
    if (check(argv) == -1 || check_double(res.a) == -1)
    {
        ft_error();
        return (0);
    }
    while ((mv = ft_get_txt(0)) != NULL)
    {
        if (check_move(&res, mv) == -1)
        {
            ft_error();
            return (0);
        }
    }
    check_win(res.a, res.b) == 1 ? ft_putstr("OK\n") : ft_putstr("KO\n");
    return (0);
}